#include <stdio.h>
#include <cstring> 
using namespace std;
typedef long long ll;
ll memo[10][30001];

double v[] = {10000, 5000, 2000, 1000, 500, 200, 100, 50, 20, 10, 5};

ll dp(int ind, int d){
    if(d == 0){
        return 1;
    }

    if(ind == 10){
        return 1;
    }

    if(memo[ind][d] != -1){
        return memo[ind][d];
    }

    ll cont = 0;
    for(int i = 0; i != 30000; i++){
        if(v[ind]*i > d){
            break;
        } 

        cont += dp(ind+1, d-v[ind]*i);
    }

    return memo[ind][d] = cont;
}

int main(){
    int d1, d2;
    memset(memo, -1, sizeof memo);
    while(scanf("%d.%d", &d1, &d2) == 2){
        d1 = d1*100+d2;
        if(d1==0){
            break;
        }
        printf("%6.2lf %16lld\n", double(d1)/100, dp(0, d1));
    }
}
