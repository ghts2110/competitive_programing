#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
int n, memo[100010][3];

int dp(vector<vector<int> > &v, int ind, int l){
    if(ind == n){
        return 0;
    }

    if(ind != 0 && memo[ind][l] != -1){
        return memo[ind][l];
    }

    int m1= 0, m2 = 0, m3 = 0;
    if(l != 0){
        m1 = dp(v, ind+1, 0) + v[ind][0];
    }
    if(l != 1){
        m2 = dp(v, ind+1, 1) + v[ind][1];
    }
    if(l != 2){
        m3 = dp(v, ind+1, 2) + v[ind][2];
    }

    int mx = max(m1, max(m2, m3));

    return memo[ind][l] = mx;
}

int main(){
    while(cin >> n){
        memset(memo, -1, sizeof(memo));

        vector<vector<int> > v(n, vector<int> (3));

        for(int i = 0; i != n; i++){
            cin >> v[i][0] >> v[i][1] >> v[i][2];
        }

        cout << dp(v, 0, -1) << endl;
    }
}