#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int n;
int cnt = 0;

bool isPrime(int num){
  if (num < 2) return false; // 1과 0은 소수가 아니다.
  for(int i = 2; i <= sqrt(num); i++){
    if(num % i == 0) return false; 
  }
  return true;
}

void go(int prev, int depth){
  if(depth < n){
    for(int i = 1; i < 10; i++){
      int next =  i + prev * 10;
      if (isPrime(next)){
        go(next, depth+1);
      }
    }
  }else{
    cout << prev << '\n';
  }
}
int main(){
  cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
  cin >> n;
  go(0,0);
  return 0;
}