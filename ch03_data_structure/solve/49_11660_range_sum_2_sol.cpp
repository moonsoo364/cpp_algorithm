#include <vector>
#include <iostream>

using namespace std;
int n, m;

void printV(vector<vector<int>> &arr){
    cout << "####" << '\n';
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }
    
}

// void printI(int i){
//     cout << "i :" << i << '\n';
// }

void minusI(int & i){
    i--;
    //printI(i);
}



int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<vector<int>> v, s;

    cin >> n >> m;
    v.resize(n, vector<int>(n));
    s.resize(n, vector<int>(n));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> v[i][j];
        }
    }
    // printV(v);
    
    // D[i][j] = D[i][j-1] + D[i-1][j] -D[i-1][j-1] + A[i][j]
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int prevY = (i > 0) ? s[i-1][j] : 0;
            int prevX = (j > 0) ? s[i][j-1] : 0;
            int prevXY = (i > 0 && j > 0) ? s[i-1][j-1] : 0;
            s[i][j] = v[i][j] + prevX + prevY - prevXY;
        }
    }
    //printV(s);

    for(int i = 0; i < m; i++){
        int sY, sX, eY, eX;
        int ret = 0;
        cin >> sY >> sX >> eY >> eX;
        // 1 1 2 3
        minusI(sY);
        minusI(sX);
        minusI(eY);
        minusI(eX);

        // result = D[x2][y2] - D[x1-1][y2] - D[x2][y1-1] + D[x1-1][y1-1]
        if(sY == eY && sX == eX){
            ret = v[eY][eX];
        }else{
            int prevX = sX < 1 ? 0 : s[eY][sX-1];
            int prevY = sY < 1 ? 0 : s[sY-1][eX];
            int prevXY = sX < 1 || sY < 1 ? 0 : v[sY - 1][sX-1];
            ret = s[eY][eX] - prevX - prevY + prevXY;
        }
        
        cout << ret << '\n';
    }

    

    return 0;
}