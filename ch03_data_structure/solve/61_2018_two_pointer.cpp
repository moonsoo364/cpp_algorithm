#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    int count = 0;
    int start = 1, end = 1, sum = 1;

    while (start <= n) {
        if (sum == n) {
            count++;
            sum -= start;
            start++;
        } else if (sum < n) {
            end++;
            sum += end;
        } else {
            sum -= start;
            start++;
        }
    }

    cout << count << '\n';
    return 0;
}
