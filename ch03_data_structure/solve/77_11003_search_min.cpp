#include<deque>
#include<iostream>

using namespace std;

struct Node {
    int n1;//index
    int n2;//value
    Node(int x, int y) : n1(x), n2(y) {}
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, s;
    cin >> n >> m;
    s = m;
    deque<Node> dq;
    for(int i = 0; i < n; i++){
        int val;
        cin >> val;

        while(!dq.empty() && dq.back().n2 > val){
            dq.pop_back();
        }

        dq.emplace_back(i, val);
        if(dq.front().n1 <= i - m){
            dq.pop_front();
        }

        cout << dq.front().n2 << " ";
        
        
    }
    return 0;
}