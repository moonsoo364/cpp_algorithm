#include <iostream>
#include <string>
using namespace std;

int main(){
    /** 표준 C++ 입출력(cin, cout)을 C 표준 입출력(scanf, printf)와 동기화하지 않도록 설정합니다.
     * 이를 통해 입출력 속도를 향상시킬 수 있지만, C 표준 입출력과 혼용하면 예상치 못한 동작이 발생할 수 있습니다.*/
    ios_base::sync_with_stdio(false);

    /** cin과 cout의 연결을 끊어줍니다. 기본적으로 cin은 입력을 받을 때 cout의 출력이 끝날 때까지 기다립니다.
     연결을 끊으면 불필요한 대기 시간이 줄어들어 입출력 속도가 개선됩니다.*/
    cin.tie(0);
    /** cout과 다른 출력 스트림의 연결을 끊습니다. 이 설정은 일반적으로 cin.tie(0)과 함께 사용됩니다.
    입출력 성능을 최적화하기 위한 설정입니다*/
    cout.tie(0); 

    // getline : 띄어쓰기가 포함된 문자열을 한 줄로 받을 때 사용
    string input;
    getline(cin, input);
    cout << "You entered: " << input << endl; 
}