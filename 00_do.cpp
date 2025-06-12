#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

struct Comp{
    bool operator()(int x, int y){
        int ax = abs(x), ay = abs(y);
        if(ax == ay) return x > y;
        return ax > ay;
    }
};

int main(){
    cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
    int n;
    cin >> n;

    priority_queue<int,vector<int>, Comp> pq;
    for(int i = 0; i < n; i++){
        int t;
        cin >> t;
        if(!t){
            if(pq.empty()){
                cout << 0 << '\n';
            }else{
                cout << pq.top() << '\n';
                pq.pop();
            }
        }else{
            pq.push(t);
        }
    }

    return 0;
}
