#include <iostream>
#include <cstring>

using namespace std;
int w[50], v[50], memo[60][1010];
int c, f;

int dp(int ind, int rest){
    if(ind == f){
        return 0;
    }

    if(memo[ind][rest] != -1){
        return memo[ind][rest];
    }

    int m = dp(ind+1, rest);
    if(rest-w[ind] >= 0){
        m = max(m, dp(ind+1, rest-w[ind]) + v[ind]);
    }

    return memo[ind][rest] = m;
}

int main(){
    int test = 1;
    while(cin >> c >> f){
        if(!c && !f){
            break;
        }

        memset(memo, -1, sizeof(memo));
        for(int i = 0; i != f; i++){
            cin >> w[i] >> v[i];
        }

        cout << "Teste " << test << endl;
        cout << dp(0, c) << endl;
        cout << endl;

        test++;
    }
}