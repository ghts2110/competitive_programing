#include <iostream>
#include <cstring>


using namespace std;
typedef long long ll;
ll memo[51];

ll dp(int n){
    if(n == 0){
        return 1;
    }

    if(n < 0){
        return 0;
    }

    if(memo[n] != -1){
        return memo[n];
    }

    return memo[n] = dp(n-1) + dp(n-2);
}

int main(){
    memset(memo, -1, sizeof memo);
    int n;
    while(cin >> n){
        if(!n){
            break;
        }

        cout << dp(n) << endl;
    }
}
