#include <iostream>
#include <vector>
#include <algorithm>  

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());  // 오름차순 정렬

    int s = 0, e = n - 1;
    int cnt = 0;

    while (s < e) {
        int sum = v[s] + v[e];
        if (sum == m) {
            cnt++;
            s++;
            e--;
        } else if (sum < m) {
            s++;
        } else {  // sum > m
            e--;
        }
    }

    cout << cnt << '\n';

    return 0;
}
