#include<algorithm>
#include<iostream>
#include<queue>
#include<vector>



using namespace std;

struct Compare {
    bool operator()(int a, int b){
        if(abs(a) == abs(b)) return a > b;
        return abs(a) > abs(b);
    }
};

int main(){
    vector<int> v = {-3, 5, -7, 1, -6};
    //priority_queue<자료형, 내부컨테이너, 정렬기준(기본 최대값 우선)
    priority_queue<int, vector<int>, Compare> pq;
    for(int i : v){
        pq.push(i);
    }
    while(!pq.empty()){
        cout << pq.top() <<'\n';
        pq.pop();
    }
    


    return 0;
}