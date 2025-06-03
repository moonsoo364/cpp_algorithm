#include <vector>

using namespace std;

int main(){
    //선언
    vector<int> a;

    //삽입
    a.push_back(1);// 마지막에 1추가
    a.insert(a.begin(), 7);// 맨 앞에 7을 삽입
    a.insert(a.begin() + 2, 10);// index 2에 위치에 10 삽입 

    //변경
    a[4] = -5;// index 4의 값을 -5로 변경

    //삭제
    a.pop_back();// 마지막 값 삭제
    a.erase(a.begin()+3);// 인덱스 3에 해당하는 값 삭제
    a.clear();// 모든 값 삭제

    //조회
    a.size();// 데이터 개수
    a.front();// 처음 값
    a.back();// 마지막 값
    a[3];// 인덱스 3에 해당하는 값
    a.at(5);// 인덱스 5에 해당하는 값
    a.begin();// 첫 번째 데이터 위치
    a.end();// 마지막 데이터 위치

}