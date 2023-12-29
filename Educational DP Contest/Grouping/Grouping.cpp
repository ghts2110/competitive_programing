#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
typedef long long ll;
ll n, memo[1<<16];

ll dp(int bt, vector<vector<int> > &v){
    ll asw = 0;

    if(memo[bt] != -1){
        return memo[bt];
    }

    for(int i = 0; i != n; i++){
        for(int j = i+1; j != n; j++){
            if((bt&(1<<i)) && (bt&(1<<j))){
                asw+=v[i][j];
            }
        }
    }

    for( int i = bt&(bt-1); i>0; i=(i-1) & bt)
    {
        asw = max(asw, dp(i, v) + dp(bt^i, v));
    }

    return memo[bt] = asw;
}

int main(){


    cin >> n;
    memset(memo, -1, sizeof memo);

    vector<vector<int> > v(n, vector<int>(n));
    for(int i = 0; i != n; i++){
        for(int j = 0; j != n; j++){
            cin >> v[i][j];
        }
    }

    cout << dp((1<<n)-1, v) << endl;
}