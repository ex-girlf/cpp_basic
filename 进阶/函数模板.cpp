#include <iostream>
using namespace std;
template <class T>
void swapT(T &a,T &b){
    T temp;
    temp = a;
    a = b;
    b = temp;
}


template<typename T>
void Order(T a[],int len){
    // int size = sizeof(a);
    
    for(int i=0;i<len;i++){
        int Maxindex=i;
        for (int j=i+1;j<len;j++){
            if(a[j]>a[Maxindex]){
                Maxindex = j;
            }
        }
        swapT(a[i],a[Maxindex]);
        
    }
  
 
}

template <class T>
void printT(T a[],int len){
    for (int i=0;i<len;i++){
        cout<<a[i]<<" ";
        
    }
    cout<<endl;
}

int main(){
    int a[] ={3,2,5,8,1,4,7};
    char b[] ="dacb";
    int lena = sizeof(a) / sizeof(int);
    int lenb = sizeof(b) / sizeof(char);
    //自动推导
    //如果用模版发生了重载，加上<>强制调模版函数，否则优先使用普通函数
    //Order(a,lena);
    Order<>(a,lena);
    printT(a,lenb);
    Order(b,lenb);
    printT(b,lenb);

    }