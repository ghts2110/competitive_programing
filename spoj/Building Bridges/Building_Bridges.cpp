#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;
int n, memo[1001];

int dp(int ind, int last, vector<pair<int, int> > &v){
    if(ind == n){
        return 0;
    }

    if(memo[ind] != -1){
        return memo[ind];
    }

    int asw = 0;
    for(int i = ind; i != n; i++){
        if(last <= v[i].second){
            asw =  max(asw, dp(i+1, v[i].second, v)+1);
        }
    }

    return memo[ind] = asw;
}

int main(){
    int t;
    cin >> t;

    while(t--){
        cin >> n;
        memset(memo, -1, sizeof memo);

        vector<pair<int, int> > v(n);
        for(int i = 0; i != n; i++){
            int num;
            cin >> v[i].first;
        }

        for(int i = 0; i != n; i++){
            int num;
            cin >> v[i].second;
        }

        sort(v.begin(), v.end());

        cout << dp(0, -1e9, v) << endl;
    }
}