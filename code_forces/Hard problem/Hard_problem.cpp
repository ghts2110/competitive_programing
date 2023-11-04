#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>

using namespace std;

int n;
long long memo[100010][2];

long long dp(int ind, vector<int> &v, vector<pair<string, string> > &vs, int last, const string& str){
    if(ind == n-1){
        return 0;
    }

    if(ind != -1 && memo[ind][last] != -1){
        return memo[ind][last];
    }

    if(!str.empty() && str > vs[ind+1].first && str > vs[ind+1].second){
        return 1e18;
    }

    long long m1 = 1e18, m2 = 1e18;

    if(str.empty() || str <= vs[ind+1].first){
        m2 = 0;
        m2 += dp(ind+1, v, vs, 0, vs[ind+1].first);
    }

    if(str.empty() || str <= vs[ind+1].second){
        m1 = v[ind+1];
        m1 += dp(ind+1, v, vs, 1, vs[ind+1].second);
    }

    return memo[ind][last] = min(m2, m1);
}

int main(){
    while(cin >> n){
        memset(memo, -1, sizeof(memo));

        vector<int> v(n);
        for(int i = 0; i != n; i++){
            cin >> v[i];
        }

        vector<pair<string, string> > vs(n);
        for(int i = 0; i != n; i++){
            string s;
            cin >> s;

            vs[i].first = s;
            string save;
            for(int j = s.size()-1; j!= -1; j--){
                save += s[j];
            }

            vs[i].second = save;
        }

        long long val = dp(-1, v, vs, 0, "");

        if(val == 1e18){
            cout << -1 << endl;
        }else{
            cout << val << endl;
        }
    }
}