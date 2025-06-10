#include<queue>
#include<iostream>

using namespace std;

int main(){
    cin.tie(0),cout.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin >> n;
    queue<int> q;
    for(int i = 1; i <= n; i++){
        q.push(i);
    }
    while (q.size() > 1) {
        q.pop();               // 1. 맨 위 카드 버림
        q.push(q.front());     // 2. 다음 맨 위 카드를 뒤로 보냄
        q.pop();               //    보낸 카드 제거
    }

    cout << q.front() << '\n'; // 마지막 한 장 출력

    return 0;
}