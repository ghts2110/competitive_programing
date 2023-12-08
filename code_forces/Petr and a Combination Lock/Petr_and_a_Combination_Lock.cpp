#include <iostream>
#include <cstring>

using namespace std;

bool memo[20][360];
int v[15];
int n;

int dp(int ind, int degrees){
    if(ind == n){
        return degrees == 0;
    }

    int l = degrees - v[ind];
    if(l < 0){
        l += 360;
    }

    int r = degrees + v[ind];
    if(r >= 360){
        r -= 360;
    }

    return dp(ind+1, l) | dp(ind+1, r);
}

int main(){
    while(cin >> n){
        memset(memo, 0, sizeof(memo));

        for(int i = 0; i != n; i++){
            cin >> v[i];
        }

        if(dp(0, 0)){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
}