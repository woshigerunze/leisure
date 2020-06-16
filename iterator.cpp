//
// Created by 葛润泽 on 2020/6/17.
//
#include <iostream>
using namespace std;

struct A_tag{};
struct B_tag{};
class A
{
public:
    using class_category=A_tag;
};
class B
{
public:
    using class_category=B_tag;
};

int main()
{

}
