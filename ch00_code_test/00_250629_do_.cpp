// 250629 코딩 테스트 연습
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
// 백조의 호수 : 3197 
// .: 물, L: 백조, X: 얼음
// 매일 물과 인접한 얼음을 녹이고 백조가 처음 만나는 일 수 구하기

int x, y;
int day = 0;
vector<vector<char>> v;
vector<vector<int>> visited;

queue<pair<int,int>> l;// 백조
queue<pair<int,int>> cq;// 현재 큐
queue<pair<int,int>> nq;// 다음 큐

vector<int> dy = {-1, 0 , 1, 0};
vector<int> dx = {0 , 1, 0 , -1};

void bfs(){
    day++;
    vector<vector<bool>> visited(y, vector<bool>(x, false));
    while(!cq.empty()){
        pair<int,int> p = cq.front();
        int qy = p.first;
        int qx = p.second;
        cq.pop();
        for(int i = 0 ; i < 4 ; i++){
            int sy = qy + dy[i];
            int sx = qx + dx[i];
            cout << "sy: " <<  sy<< '\n';
            cout << "sx: " <<  sx<< '\n';
            if (sy >= 0 && sy < y && sx >= 0 && sx < x) {
                if (!visited[sy][sx]) {
                    cout << "is passed" << '\n';
                } else {
                    cout << "already visited: " << sy << ", " << sx << '\n';
                }
            } else {
                cout << "out of bounds: " << sy << ", " << sx << '\n';
            }

            // if(sy > -1 && sy < y && sx > -1 && sx < x && !visited[sy][sx]){
            //     cout << "sy: " <<  sy<< '\n';
            //     cout << "sx: " <<  sx<< '\n';
                
            //     if(!visited[sy][sx]){
            //         visited[sy][sx] = 1;
            //         if(v[sy][sx] == 'L'){
            //             return;
            //         }
            //         if(v[sy][sx] == 'X'){
            //             nq.push({sy,sx});
            //         }
            //         if(v[sy][sx] == '.'){
            //             cq.push({sy,sx});
            //         }
            //     }
            // } 
        }
    }
    
}

int main(){
    cout.tie(0), cin.tie(0), ios::sync_with_stdio(0);
    cin >> y >> x;
    v.resize(y,vector<char>(x));
    for(int i = 0; i < y; i++){
        for(int j = 0; j < x; j++){
            cin >> v[i][j];
            //백조의 위치
            if(v[i][j] == 'L'){
                l.push({i,j});
            }
        }
    }
    cq.push(l.front());
    bfs();
    while(!nq.empty()){
        cq = nq;
        bfs();
    }
    cout << day << '\n';

    return 0;
}