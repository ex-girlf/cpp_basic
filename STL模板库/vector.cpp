#include <vector>
using namespace std;
#include <iostream>
#include <algorithm>

void printInfo(int val){
    cout<< val<<endl;
}

void test(){
    vector<int> v;
    v.push_back(10);
    v.push_back(20);

    //起始迭代器，指向容器第一个元素。
    vector<int>::iterator iter_begin = v.begin();

    //结束迭代器，指向容器最后一个元素的下一个位置.
    vector<int>::iterator iter_end = v.end();

    //第二种迭代方式
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++){
        cout<<*it<<endl;
    }
    //第三种迭代方式
    for_each(v.begin(),v.end(),printInfo);

}