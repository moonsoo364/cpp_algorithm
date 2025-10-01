#include<iostream>
#include<vector>
using namespace std;
int n, m;
vector<vector<int>> v;
vector<int> visited;

int dfs(int index, int add){
  visited[index] = 1;
  add++;
  for(int i : v[index]){
    if(!visited[i]){
      add = dfs(i,add);
    }
  }
  return add;
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
  int maxDepth = 0;
  for(int i = 0; i < n; i++){
    if(!visited[i]){
      int depth = dfs(i,0);
      maxDepth =  depth > maxDepth ? depth : maxDepth;
    }
  }
  if(maxDepth > 1){
    cout << '1' << '\n';
  }else{
    cout << '0' << '\n';
  }
  return 0;
}