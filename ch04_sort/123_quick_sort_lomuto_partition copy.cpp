#include <iostream>
#include <vector>
using namespace std;

// partition 함수 (Lomuto 방식)
int partition(vector<int> &arr, int low, int high) {
    int pivot = arr[high]; // 피벗: 마지막 원소
    int i = low - 1;       // 작은 값들의 끝 인덱스

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]); // 피벗을 제자리에 놓기
    return i + 1;
}

// 퀵정렬 재귀 함수
void quickSort(vector<int> &arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high); // 피벗 위치
        quickSort(arr, low, pi - 1);        // 왼쪽 부분
        quickSort(arr, pi + 1, high);       // 오른쪽 부분
    }
}

int main() {
    int n , m;
    cin >> n >> m;
    vector<int> v(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    quickSort(v, 0, n - 1);

    cout << v[m-1] << '\n';

    return 0;
}
