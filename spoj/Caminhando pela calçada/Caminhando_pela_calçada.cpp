#include <iostream>
#include <cmath>

using namespace std;

int gcd(int a, int b){
    if(b == 0){
        return a;
    }
    return gcd(b, a%b);
}

int main(){
    int t;
    cin >> t;

    while(t--){
        int x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        int l1 = abs(x2 - x1);
        int l2 = abs(y2 - y1);

        cout << gcd(l1, l2) + 1 << endl;
    }
}
