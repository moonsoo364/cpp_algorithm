#include <vector>
#include <iostream>

using namespace std;
int n, m;

void printV(vector<vector<int>> &arr){
    cout << "####" << '\n';
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            //cout << "arr[" << i << "][" << j << "] :"  << arr[i][j] << '\n';
            cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }
    
}

void printI(int i){
    cout << "i :" << i << '\n';
}

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
            if(j == 0){
                s[i][j] = v[i][j];
            }else{
                int prevS = s[i][j - 1];
                s[i][j] = prevS + v[i][j];
            }
        }
    }
    // printV(v);
    // printV(s);
    
    for(int i = 0; i < m; i++){
        int sY, sX, eY, eX;
        int maxI = n - 1;
        int sum = 0;
        cin >> sY >> sX >> eY >> eX;
        // 1 1 2 3
        minusI(sY);
        minusI(sX);
        minusI(eY);
        minusI(eX);
        if(sY == eY && sX == eX){
            sum = v[eY][eX];
        }else{
            for (int i = sY; i <= eY; i++){
                int part;
                int rowS = sX - 1 < 0 ? 0 : s[i][sX-1];

                if(i == sY){
                    part =  s[i][eX] - rowS;
                }else if(i == eY){
                    part = s[i][eX] - rowS;
                }else{
                    part = s[i][maxI];
                }
                //printI(part);
                sum += part;    
            }
        }
        
        cout << sum << '\n';

    }



    return 0;
}