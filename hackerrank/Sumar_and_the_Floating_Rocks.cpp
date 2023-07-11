#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int t;
    cin >> t;
    
    while(t--){
        int x1, x2, y1, y2;
        cin >> x1;
        cin >> y1;
        cin >> x2;
        cin >> y2;

        int l1 = abs(x2 - x1);
        int l2 = abs(y2 - y1);

        while(l1 != 0 && l2 != 0){
            int v = l1;
            l1 = min(l1, l2);
            l2 = max(v, l2);
            l2 %= l1;
        }

        cout << l1 + l2 - 1 << endl;
    }
    return 0;
}
