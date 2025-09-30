#include <iostream>
#include <cmath>
using namespace std;

int n;

bool isPrime(int n){
  if(n < 2) return 0; //0,1는 소수가 아니다.
  // ex 100 = 2 * 50 = 5 * 20 = 10 * 10
  // : 작은 쪽의 인수는 반드시 루트 n 에 포함된다.  
  for(int i = 2; i <= sqrt(n); i++){
    if(n % i == 0) return false; // 나누어 떨어지면 소수가 아니다.
  }
  return 1;
}
void go(int cn, int prev){
  if(cn <= n){
    int tenPrev = 10 * prev;
    for(int i = 0; i < 10; i++){
      if (isPrime(tenPrev + i)){
        go(cn+1, tenPrev + i);
      }
    }
  }else{
    cout << prev << '\n';
  }


}
int main(){
  ios::sync_with_stdio(0);cout.tie(0);
  cin >> n;
  go(1,0);
  return 0;
}