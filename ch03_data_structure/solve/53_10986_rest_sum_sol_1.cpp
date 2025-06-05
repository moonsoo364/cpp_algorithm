#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<long long> prefix_mod_count(m, 0); // 나머지별 개수 저장
    prefix_mod_count[0] = 1; // 누적합이 m으로 나누어떨어지는 경우

    long long sum = 0;
    long long answer = 0;

    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        sum += a;
        int mod = sum % m;
        if (mod < 0) mod += m; // 음수 방지
        answer += prefix_mod_count[mod]; // 같은 나머지를 가진 누적합 쌍 찾기
        prefix_mod_count[mod]++;
    }

    cout << answer << '\n';
    return 0;
}
