#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
long long  n, memo[100000][3];

long long  dp(int ind, vector<int> &row1, vector<int> &row2, int last){
    if(ind == n){
        return 0;
    }

    if(memo[ind][last] != -1){
        return memo[ind][last];
    }

    long long  m1 = 0, m2 = 0, m3 =dp(ind+1, row1, row2, 0);
    if(last != 1){
        m1 += dp(ind+1, row1, row2, 1);
        m1 += row1[ind];
    }
    if(last != 2){
        m2 += dp(ind+1, row1, row2, 2);
        m2 += row2[ind];
    }

    long long  mx = max(m3, max(m1, m2));
    return memo[ind][last] = mx;
}

int main(){
    cin >> n;

    memset(memo, -1, sizeof(memo));
    vector<int> row1(n);
    for(int i = 0; i != n; i++){
        cin >> row1[i];
    }

    vector<int> row2(n);
    for(int i = 0; i != n; i++){
        cin >> row2[i];
    }

    cout << dp(0, row1, row2, 0) << endl;
}