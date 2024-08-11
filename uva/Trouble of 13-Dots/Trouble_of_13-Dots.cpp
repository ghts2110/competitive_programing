#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int n;
int ar[30010][110];

int dp(vector<pair<int, int >> &v, int ind, long custo, int c){
    if(ind == n){
        return 0;
    }

    if(ar[custo][ind] != -1){
        return ar[custo][ind];
    }
    
    int mx = dp(v, ind + 1, custo, c);
    int save = custo + v[ind].first;
    if(save <= c || (save > c && save > 2000 && save <= c+200)){
        mx = max(mx, dp(v, ind + 1, custo + v[ind].first, c) + v[ind].second);
    }

    return ar[custo][ind] = mx;
}

int main(){
    int c;
    while(cin >> c >> n){
        memset(ar, -1, sizeof(ar));
        vector<pair<int, int>> v(n);
        for(int i = 0; i < n; i++){
            cin >> v[i].first >> v[i].second;
        }

        cout << dp(v, 0, 0, c) << "\n";
    }
}
