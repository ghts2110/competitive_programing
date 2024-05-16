#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
long long memo[1005][35];

long long dp(int ind, vector<pair<int, int>> &v, int num){
    if(ind == v.size()){
        return 0;
    }

    if(memo[ind][num] != -1){
        return memo[ind][num];
    }

    long long mx = dp(ind+1, v, num);
    if(num-v[ind].second >= 0){
        mx = max(mx, dp(ind+1, v, num-v[ind].second) + v[ind].first);
    }

    return memo[ind][num] = mx;
}

int main(){
    int t;
    cin >> t;

    while(t--){
        memset(memo, -1, sizeof memo);
        int n;
        cin >> n;

        vector<pair<int, int>> v;
        for(int i = 0; i != n; i++){
            int p, w;
            cin >> p >> w;

            v.push_back({p, w});
        }

        int g;
        cin >> g;

        long long asw = 0;
        for(int i= 0 ;i  != g; i++){
            int num;
            cin >> num;
            asw += dp(0, v, num);
        }

        cout << asw << endl;
    }
}
