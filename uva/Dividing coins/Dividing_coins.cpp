#include <iostream>
#include <cstring>

using namespace std;

int n;
int sum = 0;
int asw = 0;

int v[100];
int memo[101][20001];
void dp(int ind, int s){
    if(ind == n){
        asw = min(asw, abs(2*s-sum));  
        return;
    }

    if(memo[ind][s] != -1){
        return;
    }

    dp(ind+1, s);
    if(s+v[ind] <= sum/2){
        dp(ind+1, s+v[ind]);
    }
    
    memo[ind][s] = asw;
}

int main(){
    int t;
    scanf("%d", &t);

    while(t--){
        scanf("%d", &n);
        asw = 0;
        sum = 0;
            
        memset(memo, -1, sizeof memo);
        for(int i = 0; i != n; i++){
            cin >> v[i];
            sum += v[i]; 
        }

        asw = sum;
        dp(0, 0);
        printf("%d\n", asw);
    }
}
