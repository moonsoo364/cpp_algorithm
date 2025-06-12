#include<iostream>
#include<vector>
#include<queue>

using namespace std;

struct Comp{
    bool operator()(int x, int y){
        return x > y;
    }
};
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    //힙 기본 설정 : 최대값 먼저 pop();
    priority_queue<int, vector<int>, Comp> pq;


    auto prt = [](int x){
        cout << x << '\n';
    };

    for(int i = 0; i < n ;i++){
        int x;
        cin >> x;
        if(!x){
            if(pq.empty()){
                prt(0);
            }else{
                prt(pq.top());
                pq.pop();
            }
        }else{
            pq.push(x);
        }
        
    }



    return 0;
}