#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

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