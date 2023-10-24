#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int memo[110][110][10000];
int n, k;

int dp(int ind, int kg, int cost, vector<int> &v){
    if(kg == k){
        return memo[ind][kg][cost] = cost;
    }else if(ind == n || kg > k){
        return memo[ind][kg][cost] = 1e9;
    }

    if(memo[ind][kg][cost] != -1){
        return memo[ind][kg][cost];
    }

    int asw = 1e9;
    for(int i = 0; i != k; i++){
        if(v[i] == -1){
            continue;
        }

        int num = dp(ind+1, kg+i+1, cost+v[i], v);

        asw = min(asw, num);
    }
    return memo[ind][kg][cost] = asw;
}

int main(){
    int t;
    cin >> t;

    while(t--){
        memset(memo, -1, sizeof(memo));
        cin >> n >> k;

        if(k == 0){
            cout << -1 << endl;
            continue;
        }

        vector<int> v(k);
        for(int i= 0; i != k; i++){
            cin >> v[i];
        }

        int asw=dp(0, 0, 0,v);
        if(asw == 1e9){
            cout << -1 << endl;
        }else{
            cout << asw << endl;
        }

    }
}