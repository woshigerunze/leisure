#include <iostream>
#include <vector>
#include <type_traits>
#include <algorithm>
#include <memory>
#include <boost/smart_ptr.hpp>
using namespace std;

class shared
{
    shared_ptr<int> p;
public:
    shared(shared_ptr<int> _p):p(_p){}
    void print()
    {
        cout<<"use_count="<<p.use_count()<<" val="<<*p<<endl;
    }
    ~shared(){cout<<"destroy"<<endl;}
};
void print_func(shared_ptr<int> p)
{
    cout<<"use_count="<<p.use_count()<<" val="<<*p<<endl;
}
int main()
{
    shared_ptr<int> p(new int(100));
    shared p1(p);
    shared p2(p);
    p1.print();
    p2.print();
    *p=20;
    print_func(p);
    p1.print();
}
