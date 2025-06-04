#include<iostream>

using namespace std;


void valFunc(int n){
    cout << "in valFunc n :" << n << '\n';
    n++;
}

/**
 * 매개변수 앞에 &를 붙이면 참조(Reference) 전달이 됩니다.
 * 이걸 참조자(Reference) 또는 참조 전달(Call by Reference) 라고 부릅니다.
 */
void refFunc(int & n){
    cout << "in refFunc n : "<< n << '\n';
    n++;
}

int main(){
    int n = 5;

    valFunc(n);
    cout << "out valFunc n : " << n << '\n';//지역 변수 n 값 반환

    refFunc(n);
    cout << "out refFunc n : " << n << '\n';// refFunc에서 n++ 한 값이 반환


    return 0;
}