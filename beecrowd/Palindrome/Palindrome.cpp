#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

pair<int ,int> memo[2000][2000];
string s;

pair<int, int> dp(int l, int r, vector<bool> &v){
    if(l == r){
        return memo[l][r] = make_pair(v[l], 1);
    }

    if(l+1 == r){
        if(s[l] == s[r]){
            return memo[l][r] = make_pair(v[l]+v[r], 2);
        }
        return memo[l][r] = make_pair(v[l]||v[r], 1);
    }

    if(memo[l][r].first != -1){
        return memo[l][r];
    }

    if(s[l] == s[r]){
        pair <int ,int > m1 = dp(l+1, r-1, v);
        m1.second += 2;
        m1.first += v[l]+v[r];

        pair <int ,int > m2 = dp(l+1, r, v);

        pair <int ,int > m3 = dp(l, r-1, v);

        return memo[l][r] = max(m1, max(m2, m3));
    }

    return memo[l][r] = max(dp(l+1, r, v), dp(l , r-1, v));
}

int main(){
    int n;
    while(cin >> s >> n){
        memset(memo, -1, sizeof(memo));
        vector<bool> v(s.size(), false);
        for(int i = 0; i != n; i++){
            int num;
            cin >> num;

            v[num-1] = true;
        }

        int asw = 0;
        cout << dp(0, s.size()-1, v).second << endl;
    }
}