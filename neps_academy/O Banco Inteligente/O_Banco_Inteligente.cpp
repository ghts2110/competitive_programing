#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
int s, memo[10][5010];
vector<int> num(6);

int dp(int value, int ind, vector<int> &v){
    if(value == s){
        return 1;
    }

    if(ind == 6){
        return 0;
    }

    if(memo[ind][value] != -1){
        return memo[ind][value];
    }

    int asw = 0;
    for(int i = 0; i <= v[ind]; i++){
        if(value+(num[ind]*i) <= s){
            asw += dp(value+(num[ind]*i), ind+1, v);
        }else{
            break;
        }
    }

    return memo[ind][value] = asw;
}

int main(){
    cin >> s;
    num[0] = 2;
    num[1] = 5;
    num[2] = 10;
    num[3] = 20;
    num[4] = 50;
    num[5] = 100;

    memset(memo, -1, sizeof(memo));
    vector<int> v(6);
    for(int i = 0; i != 6; i++){
        cin >> v[i];
    }

    cout << dp(0, 0, v) << endl;
}