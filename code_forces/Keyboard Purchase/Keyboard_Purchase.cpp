#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    int n, m;
    while(cin >> n >> m){
        string s;
        cin >> s;

        vector<vector<int> > v(m, vector<int> (m));
        for(int i = 1; i != n; i++){
            int a = s[i-1] - 'a', b = s[i] - 'a';
            v[a][b]++;
            v[b][a]++;
        }

        int dp[(1<<20)];
        dp[0] = 0;

        for(int i = 1; i != (1<<m); i++){
            int x = 0;
            for(int j= 0; j != m; j++){
                if(i & (1<<j)){
                    x++;
                }
            }

            dp[i] = 1e9;
            for(int j = 0; j != m; j++){
                if(i & (1 << j)){
                    int sum = 0;
                    for(int k = 0; k != m; k++){
                        if(j == k){
                            continue;
                        }

                        if(i & (1 << k)){
                            sum += x * v[j][k];
                        }else{
                            sum -= x * v[j][k];
                        }
                    }

                    dp[i] = min(dp[i], dp[i^(1<<j)] + sum);
                }
            }
        }

        cout << dp[(1<<m)-1] << endl;
    }
}