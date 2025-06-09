#include <string>
#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    string s = "1234";
    int i = stoi(s);
    long l = stol(s);
    /**
     * float
     * 1. 4byte
     * 2. 소수점 이하 6 ~ 7 자리의 정밀도를 가진다. 
     */
    float f = stof(s);
    /**
     * double 
     * 1. 8byte
     * 2. 소수점 이하 15 ~ 16 정밀도를 가진다.
     */
    double d = stod(s);

    //long 은 windows에서 4byte 임 그래서 long long 으로 선언하여 os와 상관없이 8byte로 선언해야 함
    long long ll = 8;
    

    return 0;
}

