#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

long long n, memo[10010][2];

long long dp(int ind, int l, vector<int> &v){
    if(ind == n){
        return 0;
    }

    if(memo[ind][l] != -1){
        return memo[ind][l];
    }

    long long m = dp(ind+1, 0, v);
    if(!l){
        m = max(m, dp(ind+1, 1, v) + v[ind]);
    }

    return memo[ind][l] = m;
}

int main(){
    int t;
    cin >> t;

    for(int test = 1; test <= t; test++){
        cin >> n;
        memset(memo, -1, sizeof(memo));

        vector<int> v(n);
        for(int i= 0 ; i!= n; i++){
            cin >> v[i];
        }

        cout << "Case "<<test<<": ";
        cout << dp(0, 0, v) << endl;
    }
}
