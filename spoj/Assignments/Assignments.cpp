#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
typedef long long ll;

ll memo[1<<20];
int n;

ll dp(int bt, vector<vector<int> > &v){
    if(bt == (1<<n)-1){
        return 1;
    }

    if(memo[bt] != -1){
        return memo[bt];
    }

    int ind = 0;
    for(int i = 0; i != n; i++){
        if(bt&(1<<i)){
            ind++;
        }
    }

    ll asw = 0;
    for(int i = 0; i != n; i++){
        if(v[ind][i] && !(bt&(1<<i))){
            asw += dp(bt|(1<<i), v);
        }
    }

    return memo[bt] = asw;
}

int main(){
    int t;
    cin >> t;

    while(t--){
        memset(memo, -1, sizeof memo);
        cin >> n;

        vector<vector<int> > v(n, vector<int>(n));
        for(int i=  0; i != n; i++){
            for(int j  = 0; j != n; j++){
                cin >> v[i][j];
            }
        }

        cout << dp(0, v) << endl;
    }
}