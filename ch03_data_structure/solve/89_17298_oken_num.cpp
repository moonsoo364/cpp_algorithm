#include<vector>
#include<stack>
#include<iostream>

using namespace std;

int main(){
    cin.tie(0), cout.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin >> n;
    vector<int> v = vector<int>(n,0);
    vector<int> r = vector<int>(n,-1);
    stack<int> st;//인덱스 저장장


    for(int i = 0; i < n; i++){
        cin >> v[i];
    }


    for(int i = 0; i < n; i++){
        while(!st.empty() && v[st.top()] < v[i]){
            r[st.top()] = v[i];
            st.pop();
        }
        st.push(i);// 아직 오큰수를 못찾은 인덱스 저장장
    }
    for(int i : r){
        cout << i << '\n';
    }


    return 0;
}