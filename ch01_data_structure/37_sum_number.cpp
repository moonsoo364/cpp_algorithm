/**
 * N개의 숫자가 공백 없이 있다 이 숫자를 모두 합해 출력하는 프로그램 작성하시오 
 * 1. 숫자의 개수만큼 입력받은 값을 string형에 저장한다.
 * 2. string으로 입력받은 값을 한 칸씩 나누어 char[]형으로 변환한다.alignas
 * 3. 인덱스 0부터 n-1까지 배열을 탐색하여 결과 값을 누적한다.
 * */
#include <vector>
#include <string>
#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string in = "";
    vector<int> nums;
    cin >> in;
    int sum = 0;
    for(char ch : in){
        int n = ch - '0';
        nums.push_back(n);    
    }
    for(int n : nums){
        sum += n;
    }
    cout << sum << '\n';


    return 0;
}
