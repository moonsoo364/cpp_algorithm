#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main() {
    cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    string str = "";
    cin >> str;
    int cnt=0;
    vector<int> v = vector<int>(4,0);
    for(int i = 0 ; i < 4;i++){
        cin >> v[i];
    }
    vector<int> current(4,0);
    auto charToidx = [](char c){
        if (c == 'A') return 0;
        if (c == 'C') return 1;
        if (c == 'G') return 2;
        return 3;

    };
    for(int i = 0; i < m; i++){
        current[charToidx(str[i])]++;
    }
    auto isVal = [&]() {
        for(int i = 0; i < 4; i++){
            if(current[i] < v[i]) return false;
        }
        return true;
    };
    if(isVal()) cnt++;

    for(int i = m; i < n; i++){
        current[charToidx(str[i - m])]--;//앞문자 제거
        current[charToidx(str[i])]++;//뒷문자 제거
        if(isVal()) cnt++;
    }
    
    cout << cnt << '\n';
    return 0;
}