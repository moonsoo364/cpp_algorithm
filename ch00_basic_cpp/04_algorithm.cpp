#include <algorithm>
#include <iostream>
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
    return 0;
}