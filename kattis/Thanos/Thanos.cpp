#include <iostream>

using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        long long p, r, f;
        cin >> p >> r >> f;

        long long cont = 0;
        while(p <= f){
            cont++;
            p *= r;
        }

        cout << cont << endl;
    }
}
