#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
typedef long long ll;

ll memo[5][30001];
vector<ll> rry = {1, 5, 10, 25, 50};

ll dp(ll n, ll ind){
    if(n == 0){
        return 1;
    }
    if(ind == 5){
        return 0;
    }



    if(memo[ind][n] != -1){
        return memo[ind][n];
    }

    ll cont = 0;
    for(int i = 0; i <= 30000; i++){
        if(rry[ind] * i <= n){
            cont += dp(n-(rry[ind]*i), ind+1);
        }else{
            break;
        }
    }

    return memo[ind][n] = cont;    
}

int main(){
    memset(memo, -1, sizeof memo);
    ll n;

    while(cin >> n){
        ll asw = dp(n, 0);
        if(asw == 1){
            cout << "There is only "<<asw<<" way to produce "<<n<<" cents change." << endl;
            continue;
        }
        cout << "There are "<<asw<<" ways to produce "<<n<<" cents change." << endl;
    }
}
