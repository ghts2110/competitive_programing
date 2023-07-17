#include <iostream>

using namespace std;

int main(){
    int t;
    cin >> t;

    double cont = 0;
    while(t--){
        double q, y;
        cin >> q >> y;

        cont += q*y;
    }

    cout << cont << endl;
}
