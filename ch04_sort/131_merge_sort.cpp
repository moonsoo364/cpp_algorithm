#include<iostream>
#include<vector>
using namespace std;

//병합 함수: 투 포인터를 이용하여 두 정렬된 부분을 병합
void merge(vector<int>& arr, int left, int mid, int right){
    vector<int> temp;
    int l = left;
    int r = mid + 1;

    // 왼쪽과 오른쪽 그룹을 비교하여 작은 값부터 temp에 추가
    while(l <= mid && r <= right){
        if(arr[l] <= arr[r]) temp.push_back(arr[l++]);
        else temp.push_back(arr[r++]);
    }

    //남은 왼쪽 요소 추가
    while(l <= mid) temp.push_back(arr[l++]);

    //남은 오른쪽 요소를 추가
    while(r <= right) temp.push_back(arr[r++]);

    //temp 배열을 원래 배열에 복사
    for(int i = 0; i < temp.size(); i++){
        arr[left + i] = temp[i];
    }
}
//병합 정렬  (재귀적으로 분할)
void mergeSort(vector<int>& arr, int left, int right){
    if(left >= right) return;
    
    int mid = (left + right) / 2;

    //왼쪽 절반 정렬
    mergeSort(arr, left, mid);

    //오른쪽 절반 정렬
    mergeSort(arr, mid+1, right);

    //병합
    merge(arr, left, mid, right);
}

int main(){
    cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);

    int n;
    cin >> n;
    vector<int> v(n);

    for(int i = 0; i < n; i++)
        cin >> v[i];
    
        mergeSort(v,0,n-1);

    for(int i = 0; i < i++){
        cout << v[i] << '\n';
    }
}