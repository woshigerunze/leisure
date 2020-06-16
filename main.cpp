#include <iostream>
#include <vector>
#include <numeric>
#include <type_traits>
using namespace std;
template <typename T,int N>
struct my_add_pointer
{
    using type=typename add_pointer<typename my_add_pointer<T,N-1>::type>::type;
};

template <typename T>
struct my_add_pointer<T,0>
{
    using type=T;
};

template <typename T>
struct my_remove_pointer
{
    using type = T;
};

template <typename T>
struct my_remove_pointer<T*>
{
    using type = T;
};

template <typename ...Args>
auto sum_fold(Args... args)
{
    return (args-...);
}

class A
{
private:
    int a;
public:
    A(int _a=0):a(_a){cout<<"constructor A"<<endl;}
    A(const A& rhs)
    {
        if(&rhs==this)return;
        a=rhs.a;
        cout<<"copy A"<<endl;
    }
    A& operator=(const A& rhs)
    {
        if(&rhs==this)*this;
        a=rhs.a;
        cout<<"assign A"<<endl;
        return *this;
    }
    void set(int n){a=n;}
    void print(){cout<<"A class:"<<a<<endl;}
    virtual ~A(){cout<<"delete A"<<endl;}
};
class B:public A
{
private:
    int b;
public:
    B(int _b):b(_b){}
    B(const B& rhs):A(rhs)
    {
        if(&rhs==this)return;
        b=rhs.b;
        cout<<"copy B"<<endl;
    }
    B& operator=(const B& rhs)
    {
        if(&rhs==this)return *this;
        b=rhs.b;
        cout<<"assign B"<<endl;
        return *this;
    }
    void set(int n)
    {
        A::set(n);
    }
    void print()
    {
        A::print();
    }
    virtual ~B(){cout<<"delete B"<<endl;}
};

int main()
{

}
