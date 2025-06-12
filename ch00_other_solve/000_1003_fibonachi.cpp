#include <iostream>
using namespace std;

int fibo[41][2]; // 0~40까지 0, 1 호출 횟수 저장

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    // 초기값 설정
    fibo[0][0] = 1; fibo[0][1] = 0;
    fibo[1][0] = 0; fibo[1][1] = 1;

    // DP로 미리 계산
    for (int i = 2; i <= 40; i++) {
        fibo[i][0] = fibo[i-1][0] + fibo[i-2][0];
        fibo[i][1] = fibo[i-1][1] + fibo[i-2][1];
    }

    while (T--) {
        int n;
        cin >> n;
        cout << fibo[n][0] << ' ' << fibo[n][1] << '\n';
    }

    return 0;
}
