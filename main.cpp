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

template <typename ...Args>
auto sum_fold(Args... args)
{
    return (args-...);
}

int main()
{
    cout<<is_same<my_add_pointer<int,4>::type,int****>::value<<endl;
    cout<<is_same<remove_const<const int>::type,int>::value<<endl;
}
