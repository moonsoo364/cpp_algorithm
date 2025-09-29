#include <iostream>
#include <vector>
using namespace std;

// 4 3
// 6 1 2 3
// 1번쨰 1 2 6 3
// 2번쨰 
int quick(vector<int> &v, int high, int low){
  int pivot = v[high];
  int i = low - 1;
  for(int j = low; j < high; j++){
    if(v[j] < pivot){
      i++;
      swap(v[j],v[i]);
    }
  }
  swap(v[i+1], v[high]);
  return i + 1;
}

void partition (vector<int> &v, int high, int low){
  int pi = quick(v, high, low);
}

int main(){
  cin.tie(0);
  cout.tie(0);
  ios::sync_with_stdio(0);
  int n, m;
  cin >> n >> m;

  vector<int> v;
  v.resize(n);

  for(int i = 0; i < n; i++){
    cin >> v[i];
  }
  partition(v,n-1,0);
  cout << v[m-1] << '\n';
  return 0;
}