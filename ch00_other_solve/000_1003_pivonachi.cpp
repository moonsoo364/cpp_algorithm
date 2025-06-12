#include<iostream>

using namespace std;

int cntZ = 0;
int cntO = 0;

void fibo(int a){
    if( a == 0){
        cntZ++;
    }else if (a == 1){
        cntO++;
    }else{
        fibo(a-1), fibo(a-2);
    }
}

int main(){
    cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        int x;
        cntZ= 0,cntO = 0;
        cin >> x;
        fibo(x);
        cout << cntZ << " " << cntO << '\n';
    }

    return 0;
}