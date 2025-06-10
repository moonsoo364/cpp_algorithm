#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

struct Comp{
    bool operator()(int x, int y){
        if(abs(x) == abs(y)) x < y;
        return abs(x) < abs(y);
    }
};

int main(){
    int n;
    cin >> n;
    priority_queue<int, vector<int,Comp>> pq;
    

    return 0;
}