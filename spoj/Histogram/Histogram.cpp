#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
int n;
pair<int, int> memo[(1<<15)][110];

pair<int, int> dp(int bt, vector<int> &v, int l){
    if(bt == (1<<n)-1){
        return make_pair(l, 1);
    }

    if(memo[bt][l].first != -1){
        return memo[bt][l];
    }

    pair<int, int> asw = make_pair(0, 0);
    for(int i = 0; i != n; i++){
        if(!(bt&(1<<i))){
            pair<int, int> save = dp(bt|(1<<i), v, v[i]);
            save.first += abs(l - v[i]);

            if(save.first > asw.first){
                asw = save;
            }else if(save.first == asw.first){
                asw.second += save.second;
            }
        }
    }

    return memo[bt][l] = asw;
}

int main(){
    while(cin >> n){
        memset(memo, -1, sizeof memo);
        if(!n){
            break;
        }

        vector<int> v(n);
        for(int i= 0 ; i != n; i++){
            cin >> v[i];
        }

        pair<int, int> asw = dp(0, v, 0);
        cout << asw.first + 2*n << " " << asw.second << endl;
    }
}