#include<stack>
#include<vector>
#include<iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    stack<int> st;
    vector<char> ret;
    int num = 1;
    bool isSuccess = 1;
    for(int i = 0; i < n; i++){
        int target = 0;
        cin >> target;
        for(num; num <= target; num++){
            st.push(num);
            ret.push_back('+');
        }
        if(st.top() == target) {
            st.pop();
            ret.push_back('-');
            
        } else {
            isSuccess = 0;
            break;
        }
    }
    if(isSuccess){
        for(char ch : ret){
            cout << ch << '\n';
        }
    }else{
        cout << "NO" << '\n';
    }

    return 0;
}