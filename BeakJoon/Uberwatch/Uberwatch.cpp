#include <iostream>
#include <cstring>

using namespace std;
int n, m;
int v[300000], memo[300000];

int dp(int ind){
    if(ind >= n){
        return 0;
    }

    if(memo[ind] != -1){
        return memo[ind];
    }

    int asw = 0;
    asw = dp(ind+m) + v[ind];
    asw = max(asw, dp(ind+1));

    return memo[ind] = asw;
}

int main(){
    cin >> n >> m;

    memset(memo, -1, sizeof memo);
    for(int i = 0; i != n; i++){
        cin >> v[i];
    }

    cout << dp(m) << endl;
}
