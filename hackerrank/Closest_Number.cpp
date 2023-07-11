#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int a, b, x, y, z, t, ab;
    cin >> t;

    while(t--){
        cin >> a;
        cin >> b;
        cin >> x;
        
        y = pow(a, b);
        if(y < 1){
            cout << 0 << endl;
            break;
        }
        y %= x;
        z = x - y;

        if(z < y){
            cout << pow(a, b) + z << endl;
        }else{
            cout << pow(a, b) - y << endl;
        }
    }
    return 0;
}
