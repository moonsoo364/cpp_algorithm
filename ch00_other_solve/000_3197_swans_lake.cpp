#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
int day = 0;

vector<vector<char>> v;
vector<vector<int>> visited;
vector<vector<int>> wVisited;

queue<pair<int, int>> sq, nsq; // 백조 이동
queue<pair<int, int>> wq, nwq; // 물 확장

pair<int, int> swanStart, swanEnd; // 백조 두 마리 위치

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

bool isMeet() {
    while (!sq.empty()) {
        int y = sq.front().first;
        int x = sq.front().second;
        sq.pop();

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny >= 0 && ny < n && nx >= 0 && nx < m && !visited[ny][nx]) {
                visited[ny][nx] = 1;

                if (make_pair(ny, nx) == swanEnd) return true;

                if (v[ny][nx] == 'X') {
                    nsq.push({ny, nx});
                } else {
                    sq.push({ny, nx});
                }
            }
        }
    }
    return false;
}

void melt() {
    while (!wq.empty()) {
        int y = wq.front().first;
        int x = wq.front().second;
        wq.pop();

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny >= 0 && ny < n && nx >= 0 && nx < m && !wVisited[ny][nx]) {
                wVisited[ny][nx] = 1;

                if (v[ny][nx] == 'X') {
                    v[ny][nx] = '.';
                    nwq.push({ny, nx});
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    v.resize(n, vector<char>(m));
    visited.resize(n, vector<int>(m, 0));
    wVisited.resize(n, vector<int>(m, 0));

    int swanCount = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> v[i][j];

            if (v[i][j] == 'L') {
                if (swanCount == 0) {
                    swanStart = {i, j};
                } else {
                    swanEnd = {i, j};
                }
                swanCount++;
                wq.push({i, j}); // L도 물로 처리
            } else if (v[i][j] == '.') {
                wq.push({i, j});
            }
        }
    }

    // 백조 이동 초기화
    sq.push(swanStart);
    visited[swanStart.first][swanStart.second] = 1;

    while (!isMeet()) {
        day++;
        melt();

        sq = nsq;
        nsq = queue<pair<int, int>>();

        wq = nwq;
        nwq = queue<pair<int, int>>();
    }

    cout << day << '\n';
    return 0;
}
