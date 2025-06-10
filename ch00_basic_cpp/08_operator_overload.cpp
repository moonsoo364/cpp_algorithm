#include<algorithm>
#include<iostream>
#include<queue>
#include<vector>



using namespace std;

struct Foo {
    /**
     * c++에서 어떤 객체를 함수처럼 호출하고 싶을 때 ()연산자를 오버로딩 합니다.
     * 1. 이 구조체가 함수처럼 연결될 때
     * 2. 정수 a와 b 두개를 받아서
     * 3. 비교 결과를 bool로 반환한다.
    */
    void operator()(int x, int y) {
        cout << "called with " << x << ", " << y << '\n';
    }
};

int main(){

    //Foo 를 마치 함수처럼 사용
    Foo f;
    f(1,2);
    


    return 0;
}