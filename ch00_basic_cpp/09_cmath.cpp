#include<iostream>
#include<cmath>

using namespace std;

bool isPrime(int n){
    if(n < 2) return false;
    for(int i = 2; i< sqrt(n); i++){
        if(n % i == 0) return false;
    }
    return true;
}

int main(){
    cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
    int n;
    cin >> n;

    auto pr = [](int x, string s){
        cout << x << " " << s << '\n';
    };

    if(isPrime(n)) pr(n,"is prime");
    else pr(n,"is not prime");

    return 0;
}