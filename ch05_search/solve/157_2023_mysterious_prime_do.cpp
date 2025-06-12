#include<iostream>
#include<cmath>
using namespace std;

int num;

bool isPrime(int n){
    if(n < 2) return 0;
    int r = sqrt(n);
    for(int i = 2; i <= r; i++){
        if(n % i == 0) return 0;
    }
    return true;
}
void sol(int n, int s){
    if(s == num){
        cout << n << '\n';
        return ;
    }
    for(int i = 1 ; i <= 9; i++){
        int next = n * 10 + i;
        if(isPrime(next)) sol(next, s+1);
    }
}
int main(){
    cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
    cin >> num;

    sol(2,1);
    sol(3,1);
    sol(5,1);
    sol(7,1);

    return 0;
}