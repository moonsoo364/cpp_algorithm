#include<iostream>
#include<vector>

using namespace std;

int main(){
    int n, m, cnt = 0;
    cin >> n >> m;

    string str;
    cin >> str;
    vector<int> v = vector<int>(4, 0);

    for(int i = 0; i < 4;i++){
        cin >> v[i];
    }

    vector<int> c = vector<int>(4, 0);

    auto charToIdx = [](char c){
        if(c == 'A') return 0;
        else if(c == 'C') return 1;
        else if(c == 'G') return 2;
        return 3;
    };

    for(int i =0; i < m; i++){
        c[charToIdx(str[i])]++;
    }

    auto isVal = [&](){
        for(int i =0; i < 4;i++){
            if(c[i] < v[i]) return false; 
        }
        return true;
    };

    if(isVal()) cnt++;


    for(int i = m; i< n ; i++){
        c[charToIdx(str[i - m])]--;
        c[charToIdx(str[i])]++;
        if(isVal()) cnt++;
    }    
   
    cout << cnt <<'\n';

    return 0;
}