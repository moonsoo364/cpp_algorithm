#include<iostream>
#include<vector>
#include<algorithm>
// 5 2
using namespace std;
int quick(vector<int> & v, int low, int high){
 int pivot = v[high];
 int i = low - 1;// 가장 최근 작은 값

 for(int j = low; j < high; j++){
  if(v[j] < pivot){
    i++;
    swap(v[i], v[j]);
  }
 }

 swap(v[high],v[i+1]);
 return i+1;
}
void part(vector<int> & v, int low, int high){
  if(low < high){
    int pi = quick(v, low, high);
    part(v, low, pi-1);
    part(v, pi+1, high);
  }
}
int main (){
  cout.tie(0);cin.tie(0);ios::sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  vector<int> v;
  v.resize(n);
  for(int i = 0; i < n; i++){
    cin >> v[i];
  }
  part(v,0,n-1);
  cout << v[m-1] << '\n';
  return 0;
}