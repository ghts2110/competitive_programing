#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
int c, m;

int memo[1010][100010];

int dp(int ind, int val, vector<int> &v){
    if(val == c){
        return 1;
    }

    if(ind == m){
        return 0;
    }

    if(memo[ind][val] != -1){
        return memo[ind][val];
    }

    int asw = dp(ind+1, val, v);
    if(val + v[ind] <= c && asw==0){
        asw = dp(ind+1, val+v[ind], v);
    }

    return memo[ind][val] = asw;
}

int main(){
    cin >> c >> m;
    memset(memo, -1, sizeof(memo));

    vector<int> v(m);
    for(int i = 0; i != m; i++){
        cin >> v[i];
    }

    if(dp(0, 0, v)){
        cout << "S" << endl;
    }else{
        cout << "N" << endl;
    }
}