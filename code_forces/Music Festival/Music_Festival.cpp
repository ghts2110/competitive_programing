#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int dp[86410][(1<<10)];

int main(){
    int n;
    cin >> n;

    vector<vector<pair<int, pair<int, int> > > > v(86400);
    for(int i = 0; i != n; i++){
        int m;
        cin >> m;

        for(int j = 0; j != m; j++){
            int s, e, val;
            cin >> s >> e >> val;

            v[s].push_back(make_pair(i, make_pair(e, val)));
        }
    }

    memset(dp, -1, sizeof dp);
    dp[0][0] = 0;

    for(int i = 0; i <= 86400 ; i++){
        for(int j = 0; j != (1<<n); j++) {
            dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
        }

        for(auto it : v[i]){
            for(int j = 0; j != (1<<n); j++) {
                if(dp[i][j] != -1){
                    dp[it.second.first][j|(1<<it.first)] = max(dp[it.second.first][j|(1<<it.first)], dp[i][j] + it.second.second);
                }
            }
        }
    }

    cout << dp[86400][(1<<n)-1] << endl;

}