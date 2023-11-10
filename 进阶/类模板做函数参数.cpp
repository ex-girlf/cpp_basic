#include <string>
#include <iostream>
using namespace std;


template <class T1,class T2>
class Person{
    public:
        T1 name;
        T2 age;
        Person(T1 name,T2 age){
            this->name = name;
            this->age = age;
        }
        void showInfo(){
    cout<<this->name<<","<<this->age<<endl;
}
};
//指定传入类型
void printInfo1(Person<string,int>&p){
    p.showInfo();
    
}


void test01(){
    Person<string,int>p("孙",100);
    printInfo1(p);
}

//参数模板化
template <class T1,class T2>
void printInfo2(Person<T1,T2>&p){
    p.showInfo();
    cout<<"T1的类型名称"<<typeid(T1).name()<<endl;

}

void test02(){
    Person<string,int>p("孙",100);
    printInfo2(p);
}



//整个类模板化
template <class T>
void printInfo3(T &p){
    p.showInfo();
}

void test03(){
    Person<string,int>p("孙",100);
    printInfo3(p);
}


int main(){
    test03();
}