#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, s=0, e=0, cnt=0;
    cin >> n;
    e = n-1;
    
    vector<int> v = vector<int>(n,0);
    
    for(int i = 0; i < n; i++ ){
        cin >> v[i];
    }
    sort(v.begin(),v.end());

    for(int i = 0; i < n; i++){
        int t = v[i];
        int s = 0, e = n - 1;
        while(s < e){
            if(s == i){
                s++;
                continue;
            }
            if(e == i){
                e--;
                continue;
            }
            long sum = v[s] + v[e];
            if(sum == t){
                cnt++;
                break;
            }else if (sum < t){
                s ++;
            }else {
                e --;
            }
        } 

    }
    cout << cnt << '\n';

    return 0;
}