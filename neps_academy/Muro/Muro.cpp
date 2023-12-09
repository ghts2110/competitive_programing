#include <iostream>
#include <cstring>

using namespace std;
int n;
int memo[10010];

long long dp(int ind){
    if(ind == n){
        return 1;
    }
    if(ind > n){
        return 0;
    }

    if(memo[ind] != -1){
        return memo[ind];
    }

    return memo[ind] = (dp(ind+1) + (dp(ind +2)*4) + (dp(ind+3)*2)) % 1000000007;
}

int main(){
    while(cin >> n){
        memset(memo, -1, sizeof(memo));
        cout << dp(0) << endl;
    }
}