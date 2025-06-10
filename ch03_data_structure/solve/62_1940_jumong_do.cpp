#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;

    vector<int> v = vector<int>(n,0);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    sort(v.begin(),v.end());
    
    int s=0, e=n-1, cnt=0;

    while(s < e){
        int sum = v[s] + v[e];
        if(sum < m){
            s++;
        }else if(sum > m){
            e--;
        }else{
            cnt++;
            e--;
        }
    }

    cout << cnt << '\n';
}