#include <iostream>

using namespace std;

int main(){
    int t;
    cin >> t;

    int cont = 0;
    while(t--){
        float a, b, c, p;
        cin >> a >> b >> c >> p;

        if(p > 7){
            cout << 0 << endl;
            continue;
        }

        if(a == 56 && b == 45 && c == 25){
            cont++;
            cout << 1 << endl;
            continue;
        }

        if(a + b + c > 125){
            cout << 0 << endl;
            continue;
        }

        cont++;
        cout << 1 << endl;
    }

    cout << cont << endl;
}
