#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>> v;
vector<int> visited;


void dfs(int s, int e){

}

int main(){
    int n, m;
    cin >> n >> m;
    
    v.resize(n);
    visited.resize(n,0);

    for(int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        v[x][y]++;
        v[y][x]++;
    }

    dfs(0, n-1);

    return 0;
}