#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
/*
입력 예시 1
3
40 80 60

입력 예시 2
3
10 20 30

입력 예시 4
4
1 100 100 100

입력 예시 5
5
1 2 4 8 16
*/
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n = 0;
    float avg, sum = 0, maxN = 0;
    vector<float> v;
    
    cin >> n;
    v.resize(n);
    for(int i = 0; i < n; ++i) {
        cin >> v[i];
        //cout << i << ":"<< v[i] << '\n'; 
        maxN = max(v[i], maxN);
    }

    for(int i : v){
        float calc = (i / maxN) * 100;
        //cout << i << " : " << calc << '\n';
        sum += calc; 
        // cout << calc << '\n';
    }
    avg = sum / v.size(); 
    cout << avg << '\n';
    return 0;
}