#include<iostream>
#include<vector>

using namespace std;

int main(){
    cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);

    int n, m;
    cin >> n >> m;
    vector<int> v(n);

    for(int i = 0; i < n; i++){
        cin >> v[i];
    }

    for(int i = 0; i < m; i++){
        
        int x, y;
        cin >> x >> y;
        x--;

        int sum = 0;

        for(int j = x; j < y; j++){
            sum += v[j];
        }

        cout << sum << '\n';
    }


    return 0;
}