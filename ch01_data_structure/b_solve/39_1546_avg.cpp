#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n = 0, sum = 0;
    float avg;
    vector<int> v;
    cin >> n;
    v.resize(n); 
    for(int i = 0; i < n; ++i) {
        cin >> v[i]; 
    }
    for(int i : v){
        sum += i;
    }
    avg = sum / v.size(); 
    cout << avg << '\n';
    return 0;
}