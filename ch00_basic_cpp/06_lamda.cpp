#include <iostream>
using namespace std;

int main() {
    //기본 람다 함수
    auto sayHello = []() {
        cout << "Hello, Lambda!" << endl;
    };

    sayHello(); // 실행

    //매개변수가 있는 람다함수
    auto add = [](int a, int b) -> int {
        return a + b;
    };

    cout << add(3, 4) << endl; // 7 출력
    int x = 5;
    auto printX = [x]() {
        cout << "x is : "<<x << '\n';
    };
    printX();

    return 0;
}
