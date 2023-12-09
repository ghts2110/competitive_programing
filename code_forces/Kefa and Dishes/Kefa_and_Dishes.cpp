#include <iostream>
#include <map>
#include <bitset>
#include <cstring>

using namespace std;
int v[18];
long long mp[18][18],memo[18][300000];
int n, m, k;

long long dp(int ind, bitset<18> &bt, int last){
    if(ind == m){
        return 0;
    }

    if(last != -1 && memo[last][bt.to_ulong()] != -1){
       return memo[last][bt.to_ulong()];
    }

    long long asw = 0;
    for(int i = 0; i != n; i++){
        long long sum = 0;
        if(!bt[i]){
            bt[i] = true;
            sum = dp(ind+1, bt, i);
            if(last != -1){
                sum += mp[last][i];
            }

            sum += v[i];

            bt[i] = false;
        }

        asw = max(asw, sum);
    }

    if(last == -1){
        return asw;
    }

    return  memo[last][bt.to_ulong()] = asw;
}

int main(){
    while(cin >> n >> m >> k){
        memset(memo, -1, sizeof(memo));
        memset(mp, 0, sizeof(mp));


        for(int i = 0; i !=  n; i++){
            cin >> v[i];
        }

        for(int i = 0; i != k; i++){
            int x, y, c;
            cin >> x >> y >> c;
            x--;
            y--;

            mp[x][y] = c;
        }

        bitset<18> bt(0);
        cout << dp(0, bt, -1) << endl;
    }

}