#include <iostream>
#include <vector>

using namespace std;

long long memo[300010][3];
int high[300010], cost[300010];
int n, t;

long long dp(int ind, int l){
    if(memo[ind][l] != -1){
        return memo[ind][l];
    }

    if(ind == n){
        return 0;
    }

    long long asw = 1e18;
    for (int i = 0; i < 3; i++) {
        if(ind == 0 || high[ind] + i != high[ind-1] + l){
            asw =  min(asw, dp(ind+1, i) + (i*cost[ind]));
        }
    }

    return memo[ind][l] = asw;
}

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);

        for(int i = 0; i != n; i++){
            scanf("%d %d", high+i, cost+i);
        }

        for (int i = 0; i <= n; i++) {
            memo[i][0] = memo[i][1] = memo[i][2] = -1;
        }

        printf("%lld\n", dp(0, 0));
    }
}