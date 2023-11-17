#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;

    vector<int> v1(n), v2(m);

    for (int i = 0; i < n; i++) {
        cin >> v1[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> v2[i];
    }

    vector<vector<int> > dp(n+1, vector<int> (m+1));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if(v1[i] == v2[j]){
                dp[i+1][j+1] = max(dp[i][j]+1, max(dp[i+1][j], dp[i][j+1]));
            }else{
                dp[i+1][j+1] = max(dp[i+1][j], dp[i][j+1]);
            }
        }
    }

    int mx = dp[n][m];
    cout << n-mx << " " << m-mx << endl;
}