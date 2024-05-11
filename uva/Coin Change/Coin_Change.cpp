#include <iostream>
#include <cstring>

using namespace std;
int memo[5][7490];
int v[] = {50, 25, 10, 5};

int dp(int ind, int sum){
    if(ind == 4){
        return 1;
    }

    if(memo[ind][sum] != -1){
        return memo[ind][sum];
    }

    int cont = 0;
    for(int i = 0; i != 1498; i++){
        if(sum - v[ind]*i >= 0){
            cont += dp(ind+1, sum-v[ind]*i);
        }else{
            break;
        }
    }

    return memo[ind][sum] = cont;
}

int main(){
    int n;

    memset(memo, -1, sizeof memo);
    while(cin >> n){
        cout << dp(0, n) << endl;
    }
}
