#include <iostream>
#include <deque>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, l;
    cin >> n >> l;

    deque<pair<int, int>> dq;

    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;

        // 1. 윈도우 범위를 벗어난 값 제거
        while (!dq.empty() && dq.front().first <= i - l)
            dq.pop_front();

        // 2. 현재 값보다 큰 값은 모두 제거 (최솟값 유지)
        while (!dq.empty() && dq.back().second > a)
            dq.pop_back();

        // 3. 현재 값 추가
        dq.emplace_back(i, a);

        // 4. 현재 슬라이딩 윈도우에서의 최솟값 출력
        cout << dq.front().second << ' ';
    }

    return 0;
}
