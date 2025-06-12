#include<iostream>
#include<vector>

using namespace std;
vector<int> v;

int part(int l , int r){
    int pivot = v[r];
    int i = l - 1;//피벗보다 작은 값의 마지막 인덱스

    for(int j = l; j < r; j++){
        if(v[j] <= pivot){
            i++;
            swap(v[j], v[i]);
        }
        
    }

    swap(v[i+1], v[r]);
    return i + 1;
}

void quick(int l, int r){
    if(l < r){
        int pivotIndex = part(l, r);
        quick(l ,pivotIndex - 1);
        quick(pivotIndex+1, r);
    }
}

int main(){
    cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);

    int n, m;
    cin >> n >> m;
    v.resize(n);
    for(int i = 0; i < n; i++){
        cin >> v[i] ;
    }

    quick(0, n-1);
    cout << v[m-1] << '\n';
    return 0;
}