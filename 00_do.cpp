#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<int> v(n);

    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    sort(v.begin(),v.end());

    int cnt=0;
   for(int i = 0; i<n;i++){
    int t = v[i];
    int s=0, e=n-1;
    while( s < e){
        if(s == i){s++; continue;}
        if(e == i){e--; continue;}
        long long sum = (long long)v[s] + v[e];
        if(t == sum){
            cnt++;
            break;
        }else if(t > sum){
            s++;
        }else{
            e--;
        }
     }
   }
    cout << cnt << '\n';
    
    


    return 0;
}