#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int R, C;
vector<vector<char>> lake;
pair<int, int> swan[2];

vector<vector<bool>> waterVisited;
vector<vector<bool>> swanVisited;

queue<pair<int, int>> waterQ, nextWaterQ;
queue<pair<int, int>> swanQ, nextSwanQ;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

void init() {
    cin >> R >> C;
    lake.resize(R, vector<char>(C));
    waterVisited.assign(R, vector<bool>(C, false));
    swanVisited.assign(R, vector<bool>(C, false));

    int swanCount = 0;
    for (int i = 0; i < R; ++i) {
        string row;
        cin >> row;
        for (int j = 0; j < C; ++j) {
            lake[i][j] = row[j];
            if (lake[i][j] != 'X') {
                waterQ.push({i, j});
                waterVisited[i][j] = true;
            }
            if (lake[i][j] == 'L') {
                swan[swanCount++] = {i, j};
            }
        }
    }
    swanQ.push(swan[0]);
    swanVisited[swan[0].first][swan[0].second] = true;
}

bool canMeet() {
    while (!swanQ.empty()) {
        auto [y, x] = swanQ.front(); swanQ.pop();

        for (int d = 0; d < 4; ++d) {
            int ny = y + dy[d];
            int nx = x + dx[d];
            if (ny < 0 || ny >= R || nx < 0 || nx >= C || swanVisited[ny][nx]) continue;
            swanVisited[ny][nx] = true;

            if (lake[ny][nx] == '.') {
                swanQ.push({ny, nx});
            } else if (lake[ny][nx] == 'X') {
                nextSwanQ.push({ny, nx});
            } else if (lake[ny][nx] == 'L') {
                return true; // 다른 백조를 만남
            }
        }
    }
    return false;
}

void meltIce() {
    while (!waterQ.empty()) {
        auto [y, x] = waterQ.front(); waterQ.pop();
        for (int d = 0; d < 4; ++d) {
            int ny = y + dy[d];
            int nx = x + dx[d];
            if (ny < 0 || ny >= R || nx < 0 || nx >= C || waterVisited[ny][nx]) continue;

            if (lake[ny][nx] == 'X') {
                lake[ny][nx] = '.';
                nextWaterQ.push({ny, nx});
                waterVisited[ny][nx] = true;
            }
        }
    }
}

int solve() {
    int day = 0;
    while (true) {
        if (canMeet()) return day;
        meltIce();

        // 다음 날 셋업
        swanQ = nextSwanQ;
        waterQ = nextWaterQ;

        while (!nextSwanQ.empty()) nextSwanQ.pop();
        while (!nextWaterQ.empty()) nextWaterQ.pop();

        day++;
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    init();
    cout << solve() << '\n';
    return 0;
}
