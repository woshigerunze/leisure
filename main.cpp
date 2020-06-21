#include <iostream>
#include <vector>
#include <type_traits>
#include <algorithm>
#include <thread>
using namespace std;

template <typename ...Args>
auto sum_fold(Args... args)
{
    return (args+...);
}

template <typename T>
typename enable_if<is_same<T,int>::value,T>::type f(T t)
{
    cout<<1<<endl;
}
template <typename T>
void g(T t)
{
    if constexpr(is_same<T,int>::value)cout<<1<<endl;
    else cout<<2<<endl;
}
int main()
{
    g(char());
}
