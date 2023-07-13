#include <iostream>
#include <vector>

using namespace std;

int main(){
    int a1, a2, k1, k2, n;
    cin >> a1 >> a2 >> k1 >> k2 >> n;

    int mn = (a1 * (k1-1)) + (a2 * (k2-1)), mx = 0;
    if(mn >= n){
        cout << 0 << " ";
    }else{
        cout << n - mn << " ";
    }

    if(k1 < k2){
        mx += min(a1, n/k1);
        n -= mx * k1;

        mx += min(a2, n/k2);
        
        cout << mx << endl;
    }else{
        mx += min(a2, n/k2);
        n -= mx * k2;

        mx += min(a1, n/k1);

        cout << mx << endl;
    }
}
