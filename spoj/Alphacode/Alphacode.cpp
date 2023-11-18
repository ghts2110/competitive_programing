#include <iostream>
#include <string>
#include <cstring>

using namespace std;

string s;
int memo[5010];

int dp(int ind){
    if(ind == s.size()){
        return 1;
    }

    if(memo[ind] != -1){
        return memo[ind];
    }


    int m = 0;
    if(s[ind] != '0'){
        m += dp(ind+1);

        if(ind != s.size()-1 && ((s[ind]-48)*10)+s[ind+1]-48 <= 26){
            m += dp(ind+2);
        }
    }

    return memo[ind] = m;
}

int main(){
    while(cin >> s){
        if(s == "0"){
            break;
        }

        memset(memo, -1, sizeof(memo));
        cout << dp(0) << endl;
    }
}