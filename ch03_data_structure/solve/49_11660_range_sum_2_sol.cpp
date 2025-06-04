#include <vector>
#include <iostream>

using namespace std;
int n, m;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> a(n+1, vector<int>(n+1,0));
    vector<vector<int>> d(n+1, vector<int>(n+1,0));

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> a[i][j];
            d[i][j] = d[i][j-1] + d[i-1][j] - d[i-1][j-1] + a[i][j];
        }
    }

    for(int j = 0; j < m; j++){
            int y1, x1, x2, y2;
            cin >> y1 >> x1 >> y2 >> x2;

            int result = d[y2][x2] - d[y1-1][x2] - d[y2][x1-1] + d[y1-1][x1-1];
            cout << result << '\n';
        }

    return 0;
}