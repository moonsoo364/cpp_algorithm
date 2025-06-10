#include <vector>
#include <string>
#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string in = "";
    vector<int> nums;
    cin >> in;
    int sum = 0;
    for(char ch : in){
        int n = ch - '0';
        nums.push_back(n);    
    }
    for(int n : nums){
        sum += n;
    }
    cout << sum << '\n';


    return 0;
}
