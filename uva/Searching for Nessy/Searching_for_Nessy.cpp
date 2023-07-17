#include <iostream>

using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        int x, y;
        cin >> x >> y;

        int cont1 = 0;
        cont1 += (x-2)/3;
        if((x-2)%3 != 0){
            cont1++;
        }

        int cont2 = 0;
        cont2 += (y-2)/3;
        if((y-2)%3 != 0){
            cont2++;
        }

        cout << cont1 * cont2 << endl;
    }
}
