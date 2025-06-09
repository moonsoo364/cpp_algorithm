#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main (){
    
    int ret;
    int sm = 1;
    int lg = 100;

    //큰 수 반환
    ret = max(sm,lg);// lg 반환
    cout << ret << '\n';
    
    //작은 수 반환
    ret = min(sm,lg);;//sm 반환
    cout << ret << '\n';

    //오름차순 정렬
    vector<int> v = {1,7,2,9};
    sort(v.begin(),v.end());
    //내림차순 정렬
    sort(v.begin(),v.end(),greater<int>());

    return 0;
}