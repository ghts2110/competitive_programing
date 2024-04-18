#include <iostream>

using namespace std;
typedef long long ll;

int main(){
    ll a, b;
    while(cin >> a >> b){
        ll cont1 = 0;
        a--;
        for(int i = 1; i <= 62; i++){
            cont1 += (a/(ll(1)<<i))*(ll(1)<<(i-1));
            if(a%(ll(1)<<i) >= (ll(1)<<i)/2){
                cont1+= a%(ll(1)<<i) - (ll(1)<<i)/2+1;
            }
        }

        ll cont2 = 0;
        for(int i = 1; i <= 62; i++){
            cont2 += (b/(ll(1)<<i))*(ll(1)<<(i-1));
            if(b%(ll(1)<<i) >= (ll(1)<<i)/2){
                cont2+= b%(ll(1)<<i) - (ll(1)<<i)/2+1;
            }
        }

        cout << cont2 - cont1 << endl;
    }
}
