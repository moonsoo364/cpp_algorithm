#include<iostream>
#include<vector>

using namespace std;

// 파티션 함수: 피벗 기준으로 오른쪽 왼쪽 나눔
int part(vector<int>& arr, int left, int right){
    //arr = {5, 3, 8, 4, 2, 7, 1, 10}
    //left = 0, right = 7
    int pivot = arr[right];// 마지막 값을 피벗으로 설정
    int i = left - 1;// 피벗 보다 작은 값들의 마지막 인덱스

    for(int j = left; j < right; ++j){
        if(arr[j] <= pivot){
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[right]);// 피벗을 정렬된 위치로 이동
    return i + 1;
}

void quick(vector<int>& arr, int left, int right){
    if(left < right){
        int pivotIdx = part(arr, left, right);
        quick(arr, left, pivotIdx -1);//왼쪽 부분 정렬
        quick(arr, pivotIdx + 1, right);//오른쪽 부분 정렬
    }
}

int main(){
    vector<int> data = {5, 3, 8, 4, 2, 7, 1, 10};
    
    cout << "Before" << '\n';
    for(int n : data) cout << n << ' ';
    cout << '\n';

    quick(data,0, data.size() - 1);

    cout << "After sorting : ";
    for(int n : data) cout << n << ' ';
    cout << '\n';

    return 0;
}