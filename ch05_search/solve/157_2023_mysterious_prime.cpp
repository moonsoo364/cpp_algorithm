#include<iostream>
#include<cmath>
using namespace std;

int n;

int isPrime(int x){
    if(x < 2) return false;
    int root = sqrt(x);
    for(int i = 2; i < root; i++){
        if(x % i == 0) return false;
    }
    return true;
}

void dfs(int num, int len){
    if(len == n){
        cout << num << '\n';
        return;
    }

    for(int i = 1; i <= 9; i++){
        int next = num * 10 + i;
        if(isPrime(next)) dfs(next, len+1);
    }
}

int main(){
    cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);

    cin >> n;

    //1의 자리 소수부터 시작
    dfs(2,1);
    dfs(3,1);
    dfs(5,1);
    dfs(7,1);

    return 0;

}