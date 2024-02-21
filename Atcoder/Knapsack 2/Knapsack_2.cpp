#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
int memo[110][100010];
int n, val[100], weight[100];

long long dp(int ind, int v){
    if(ind == n){
        if(v == 0){
            return 0;
        }
        return 1e9 + 1;
    }

    if(memo[ind][v] != -1){
        return memo[ind][v];
    }

    long long m = dp(ind+1, v);
    if(v - val[ind] >= 0){
        m = min(m, dp(ind+1, v-val[ind])+weight[ind]);
    }

    return memo[ind][v] = m;
}

int main(){
    int w;
    scanf("%d %d", &n, &w);
    memset(memo, -1, sizeof(memo));

    int mx_v = 0;
    for(int i = 0; i != n; i++){
        scanf("%d %d", weight+i, val+i);
        mx_v += val[i];
    }

    for(int i = mx_v; i > 0; i--) {
        if(dp(0, i) <= w){
            printf("%d\n", i);
            return 0;
        }
    }
    printf("0\n");
}