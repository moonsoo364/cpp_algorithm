#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int n,m;
int day = 0;

vector<vector<char>> v;
vector<vector<int>> visited;

queue<pair<int,int>> s;//백조의 처음 위치

queue<pair<int,int>> sq;// 백조가 이동할 위치
queue<pair<int,int>> nsq;

queue<pair<int,int>> wq;
queue<pair<int,int>> nwq;


void print(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << v[i][j];
        }
        cout << '\n';
    }
}
// 백조가 만났는 지 판단, 마지막으로 인접한 얼음 위치 nsq에 push
bool isMeet(){

    return false;
}
void melt(){

}
int main(){
    cout.tie(0), cin.tie(0), ios_base::sync_with_stdio(0);
    cin >> n >> m;
    v.resize(n,vector<char>(m,0));
    int sCnt = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> v[i][j];
            if(v[i][j] == 'L'){
                s.push({i,j});
            }else if(v[i][j] == 'X'){
                wq.push({i,j});
            }
        }
    }
    while(!isMeet()){
        melt();

    }
    cout << day << '\n';
    //print();
    return 0;
}