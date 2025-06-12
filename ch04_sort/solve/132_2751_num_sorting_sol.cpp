#include<iostream>
#include<vector>

using namespace std;

vector<int> v;
vector<int> t;
void merge(int s, int e){
    int d  = e - s;
    if(d < 1){
        return ;
    }
    int m = (s + e) / 2;
    merge(s, m);
    merge(m + 1, e);

    for(int i = s; i <= e; i++){
        t[i] = v[i];
    }

    int k = s;
    int is = s;
    int im = m + 1;

    //두 그룹을 병합하는 로직
    while(is <= m && im <= e){
        if(t[is] > t[im]){
            v[k] = t[im];
            k++;
            im++;
        }
        else{
            v[k] = t[is];
            k++;
            is++;
        }
    }

    //한쪽 그룹에 남아있는 값 정리하기
    while(is <= m){
        v[k] = t[is];
        k++;
        is++;
    }
    while(im <= e){
        v[k] = t[im];
        k++;
        im++;
    }
}
int main(){
    cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);

    int n;
    cin >> n;
    v.resize(n,0);
    t.resize(n,0);

    for(int i = 0; i < n; i++){
        cin >> v[i];
    }

    merge(0, n-1);
    for(int i = 0; i < n; i++){
        cout << v[i] << '\n';
    }

}
