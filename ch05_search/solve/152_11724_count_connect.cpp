#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>> graph;//인접 리스트
vector<bool> visited;

int dfs(int node){
    visited[node] = 1;

    for(int next : graph[node]){
        if(!visited[next]){
            dfs(next);
        }
    }
}

int main(){
    cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);

    int n, m;
    cin >> n >> m;
    
    visited.resize(n+1);
    graph.resize(n+1);

    for(int i = 0 ; i < m; i++){
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);// 무방향 그래프
    }

    int cnt = 0;
    
    for(int i = 1; i <=n ; i++){
        if(!visited[i]){
            dfs(i);
            cnt++;
        }
    }
    cout << cnt << '\n';

    return 0;
}