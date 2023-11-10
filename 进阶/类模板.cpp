#include <string>
#include <iostream>
using namespace std;

//可以默认指定默认参数
//template<class T1,class T2 = int>

/*
类模版中的成员函数在调用时才会被创建
函数模板在开始就会被创建
*/
template<class T1,class T2>
class Person{
    public:
        T1 m_name;
        T2 m_age;
        Person(T1 name,T2 age){
            this->m_name = name;
            this->m_age = age;
        }
};

void test(){
    Person<string,int> p1("张三",8);
}