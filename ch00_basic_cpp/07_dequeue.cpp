#include<deque>
#include<iostream>
using namespace std;

int main(){
    deque<int> dq;
    dq.push_back(10);//뒤에 10 삽입
    dq.push_front(5);//앞에 5 삽입

    cout<< dq.front() << '\n';//5
    cout<< dq.back() << '\n';//10

    dq.pop_front(); //앞의 5제거
    dq.pop_back();// 뒤의 10제거

    return 0;
}