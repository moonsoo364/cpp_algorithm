#include <vector>
#include <iostream>
using namespace std;

int main (){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<int> v;
    vector<int> rs;

    int n, m;
    cin >> n >> m;
    v.resize(n);
    rs.resize(n);

    for(int i = 0; i < v.size(); i++){
        cin >> v[i];
        int cur = v[i];
        if(i == 0){
            rs[0] = cur;
        }else{
            int prev = rs[i-1];
            rs[i] = cur + prev;
        }

    }
    // for(int i : rs){
    //     cout << "rs : "<< i << '\n';
    // }


    for(int i = 0; i < m; i++){
        int s, e, si, ei, ret;
        cin >> s >> e;
        si = s - 2;
        ei = e - 1;


        if(si < 0 ){
           ret = rs[ei];
        }else if(s == e){
            ret = v[ei];
        }else{
            ret = rs[ei] - rs[si]; 
        }

        cout << ret << '\n';
        

    }


    return 0;
}