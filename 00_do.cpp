#include<vector>
#include<iostream>

using namespace std;
int count[10001];
int main(){
    cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
    int n, x;
    cin >> n;

    while(n--){
        cin >> x;
        count[x]++;
    }

    for(int i =1; i < 10000; i++){
        while(count[i]--){
            cout << i << '\n';
        }
    }
    return 0;
}