#include <iostream>
#include <string>

using namespace std;

template<class T>
class Myarray{
    
public:
    //有参构造
    Myarray(int capacity){
        cout<<"调用有参构造"<<endl;
        this->m_Capacity = capacity;
        this->m_Size = 0;
        this->pAddress = new T[this->m_Capacity];
    }
    //拷贝构造
    Myarray(const Myarray &arr){
        cout<<"调用拷贝构造"<<endl;

        this->m_Capacity = arr.m_Capacity;
        this->m_Size = arr.m_Size;
        //系统默认写法
        //this->pAddress = arr.pAddress;
        //深拷贝
        this->pAddress = new T[arr.m_Capacity];
        //将数组原有数据拷贝过来
        for (int i = 0; i < this->m_Size; i++){
            this->pAddress[i] = arr.pAddress[i];
        }
    }

    //operator= 防止浅拷贝 a = b = c 要返回自身引用
   Myarray& operator=(const Myarray & arr){
        cout<<"调用运算重载"<<endl;

        if(this->pAddress != NULL){
            delete [] this->pAddress;
            this->pAddress = NULL;
            this->m_Capacity =0;
            this->m_Size = 0;
        }
        this->m_Capacity = arr.m_Capacity;
        this->m_Size = arr.m_Size;
        this->pAddress = new T[arr.m_Capacity];
        for ( int i = 0; i<this->m_Size ;i++){
            this->pAddress[i] = arr.pAddress[i];
        }
        return *this;

   }

   void Push_back(const T & val){
        if(this->m_Capacity == this->m_Size){
            return;
        }
        this->pAddress[this->m_Size] = val;
        this->m_Size ++;

   }

    void Pop_back(){
        if(this->m_Size == 0){
            return;
        }
        this->m_Size--;
    }
    
    //析构函数
    ~Myarray(){
        cout<<"调用析构函数"<<endl;
        
        if(this->pAddress != NULL){
            delete [] this->pAddress;
            this->pAddress = NULL;
        }

    }

private:
    int m_Capacity;
    int m_Size;
    T * pAddress;
    
};