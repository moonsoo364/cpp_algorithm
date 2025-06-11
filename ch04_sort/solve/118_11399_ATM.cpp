#include<iostream>
#include<vector>

using namespace std;

int main(){
    cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<int> v(n);

    // v = {3, 1, 4, 3, 2}
    for (int i = 0; i < n; i++){
        cin>> v[i];
    }

    //simule : v[0] = 3, v[1] = 1
    for(int i = 1; i < n; i++){
        int val = v[i];// 1
        int j = i - 1;

        while(j >= 0 && v[j] > val){// j = 0, 3 > 1
            v[j+1] = v[j];// v[1] = 3
            j--;//i=-1
        }
        v[j+1] = val;//v[0] = 1
    }
    int sum=0, cur=0;

    // v= {1,2,3,3,4}
    //1 + 3 + 6 + 9 + 13
    for(int i = 0; i < n; i++){
        cur += v[i];//1, 3, 6, 9, 13
        sum += cur;//1, (1+3), (1+3+6), (1+3+6+9), (1+3+6+9+13) 
    }

    cout << sum << '\n';

    return 0;
}