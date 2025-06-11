#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;

int main(){
    cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);

    string str;
    cin >> str;
    int s = str.size();
    vector<int> v(s);

    for(int i = 0; i < s; i++){
        int n = str[i] - '0';
        v[i] = n;
    }

    sort(v.begin(),v.end(),greater<int>());
    for(int i : v){
        cout << i;
    }

    
}