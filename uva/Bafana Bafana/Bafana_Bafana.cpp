#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int t;
    cin >> t;

    int cont = 1;
    while(t--){
        int n, k, p;
        cin >> n >> k >> p;

        p %= n;
        int save = p;
        p -= min(n-k, save);
        k += min(n-k, save);
       
        printf("Case %d: ", cont);
        cont++;
        if(p == 0){
            cout << k << endl;
            continue;
        }

        if(k == n){
            cout << p << endl;;
        }
    }
}
