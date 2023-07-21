#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        int n, mn = 1e9, mx = 0;
        cin >> n;
        for(int i = 0; i != n; i++){
            int num;
            cin >> num;

            mn = min(mn, num);
            mx = max(mx, num);
        }

        cout << (mx - mn) * 2 << endl;
    }
}
