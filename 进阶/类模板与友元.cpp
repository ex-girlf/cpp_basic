#include <iostream>
#include <string>

using namespace std;

template <class T1,class T2>
class Person{
    public:
        Person(T1 name,T2 age){
            this->m_name = name;
            this->m_age = age;
        }
    friend void printInfo(Person<T1,T2> &p){
            cout<<p.m_name<<p.m_age<<endl;
    }
    

    private:
        T1 m_name;
        T2 m_age;
};

void test(){
    Person<string,int>p("sun",12);
    printInfo(p);
}

int main(){
    test();
}