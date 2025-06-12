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

    sort(v.begin(), v.end());

    int sum=0, prev=0;
    for(int i = 0; i < n; i++){
        prev += v[i];
        sum += prev;
    }

    cout << sum << '\n';

    return 0;
}