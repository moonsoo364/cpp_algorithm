#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int n, m;
vector<vector<int>> v;
vector<int> visited;
int temp = 0;
int found = 0;

void dfs(int node, int depth){
  if(found) return;
  if(depth == 4){
    found = 1;
    return;
  }

  visited[node] = 1;
  for(int i : v[node]){
    if(!visited[i]){
      dfs(i, depth + 1);
      if(found) return;
    }
  }

}

int main(){
  cin >> n >> m;
  v.resize(n+1);
  visited.resize(n+1);

  for(int i = 0; i < m; i++){
    int x, y;
    cin >> x >> y;
    v[x].push_back(y);
    v[y].push_back(x);
  }

  for(int i = 0; i < n && !found ; i++){
    dfs(i,0);
  }
  cout << found << '\n';
  return 0;
}