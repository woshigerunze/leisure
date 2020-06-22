#include <iostream>
#include <vector>
#include <type_traits>
#include <boost/thread.hpp>
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

int main()
{

}
