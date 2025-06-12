#include<iostream>
#include<vector>
using namespace std;

vector<int> v, t;
long long cnt = 0; // 역순쌍은 최대 n(n-1)/2 = 약 125억 → long long 필요

void merge(int s, int e){
    if(e - s < 1) return;
    int m = (s + e) / 2;

    merge(s, m);
    merge(m + 1, e);

    for(int i = s; i <= e; i++) t[i] = v[i];

    int k = s, is = s, im = m + 1;
    while(is <= m && im <= e){
        if(t[is] > t[im]){
            v[k++] = t[im++];
            cnt += (m - is + 1); // 왼쪽에 남은 원소 수만큼 역순쌍 발생
        } else {
            v[k++] = t[is++];
        }
    }
    while(is <= m) v[k++] = t[is++];
    while(im <= e) v[k++] = t[im++];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    v.resize(n);
    t.resize(n);

    for(int i = 0; i < n; i++) cin >> v[i];

    merge(0, n - 1);

    cout << cnt << '\n';
    return 0;
}
