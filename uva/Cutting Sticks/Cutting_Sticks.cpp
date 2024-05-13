#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
typedef long long ll;
int l, n;
int v[55];
ll memo[55][55];

ll dp(int left, int right){
    if(memo[left][right] != -1){
        return memo[left][right];
    }
    if(left + 1 == right){
        return memo[left][right] = 0;
    }

    ll asw = 1e18;
    for(int i = left+1; i< right; i++){
        asw = min(asw, dp(left, i) + dp(i, right) + v[right]-v[left]);
    }

    return memo[left][right] = asw;
}

int main(){
    while(cin >> l){
        if(!l){
            break;
        }

        cin >> n;

        for(int i = 1; i <= n; i++){
            cin >> v[i];
        }
        v[0] = 0;
        v[n+1] = l;
        
        memset(memo, -1, sizeof memo);

        cout << "The minimum cutting is " << dp(0, n+1) << "." << endl;
    }
}
