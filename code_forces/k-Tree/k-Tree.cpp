#include <iostream>
#include <cstring>

using namespace std;

int memo[110][110][2];

long long dp(int n, int k, int d, long long cont, bool b, int ind){
    if(cont == n && b){
        return 1;
    }

    if(memo[ind][cont][b] != -1){
        return memo[ind][cont][b];
    }

    long long sum = 0;
    for(int i = 1; i <= k; i++){
        bool val = false;
        if(i >= d){
            val = true;
        }

        if(cont+i <= n){
            sum += dp(n, k, d, cont+i, b|val, ind+1) % 1000000007;
        }
    }

    return memo[ind][cont][b] = sum % 1000000007;
}

int main(){
    int n, k, d;
    while(cin >> n >> k >> d){
        memset(memo, -1, sizeof(memo));
        cout << dp(n, k, d, 0, false, 0) << endl;
    }
}
