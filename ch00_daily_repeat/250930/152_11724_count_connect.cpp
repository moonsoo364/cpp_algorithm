#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<vector<int>> v;
vector<int> visited;

void dfs(int index){
    visited[index] = 1;
    for(int i : v[index]){
        if(!visited[i]){
            dfs(i);
        }
    }
}
int main(){
    cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
    cin >> n >> m;
    v.resize(n+1);
    visited.resize(n+1);

    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            dfs(i);
            cnt++;
        }
    }
    cout << cnt << '\n';
    return 0;
}