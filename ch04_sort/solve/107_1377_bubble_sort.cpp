#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;

int main(){
    cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<pair<int,int>> v(n);
    
    for(int i = 0; i < n; i++){
        cin >> v[i].first;
        v[i].second = i;
    }

    sort(v.begin(),v.end());
    int ans=0;
    for(int i = 0 ; i < n; i++){
        int moved = v[i].second - i;
        ans = max(ans, moved);
    }
    cout << ans + 1 <<'\n';
    return 0;
}