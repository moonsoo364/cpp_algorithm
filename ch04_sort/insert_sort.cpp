#include <iostream>
#include <vector>
using namespace std;

void insertionSort(vector<int> & arr){
    int n = arr.size();

    for(int i = 1; i < n; i++){
        int key = arr[i];//1. 현재 선택한 데이터
        int j = i - 1;

        // 2. 정렬된 부분에서 key가 삽입될 위치를 탐색
        while(j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];// 3. shift 연산
            j--;
        }

        arr[j + 1] = key;// 4. 삽입 위치에 key 삽입
    }
}

int main(){
    vector<int> arr = {5, 3, 8, 4 ,1};
    insertionSort(arr);

    //출력
    for(int i : arr){
        cout << i << ' ';
    }
    
    return 0;
}