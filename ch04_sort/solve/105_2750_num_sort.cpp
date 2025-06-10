#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;

int main(){
    cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);

    int n;
    cin >> n;
    vector<int> v = vector<int>(n,0);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    sort(v.begin(),v.end());
    for(int i : v){
        cout << i << '\n';
    }

}