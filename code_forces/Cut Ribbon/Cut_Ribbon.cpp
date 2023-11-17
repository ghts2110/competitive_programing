#include <iostream>
#include <cstring>

using namespace std;

int a, b, c;
pair<int, bool> memo[4010][3];

pair<int, bool> dp(int n, int l){
    if(n == 0){
        return make_pair(0, true);
    }else if(n < 0){
        return make_pair(0, false);
    }

    if(memo[n][l].first != -1){
        return memo[n][l];
    }

    pair<int, bool> m1 = dp(n-a, 0);
    if(m1.second){
        m1.first++;
    }

    pair<int, bool> m2 = dp(n-b, 1);
    if(m2.second){
        m2.first++;
    }

    pair<int, bool> m3 = dp(n-c, 2);
    if(m3.second){
        m3.first++;
    }

    pair<int, bool> mx = make_pair(0, false);
    if(m1.second){
        mx = max(mx, m1);
    }
    if(m2.second){
        mx = max(mx, m2);
    }
    if(m3.second){
        mx = max(mx, m3);
    }

    return memo[n][l] = mx;
}

int main(){
    int n;

    while(cin >> n >> a >> b >> c){
        memset(memo, -1, sizeof(memo));
        pair<int, bool> p = dp(n, 0);
        cout << p.first << endl;
    }
}
