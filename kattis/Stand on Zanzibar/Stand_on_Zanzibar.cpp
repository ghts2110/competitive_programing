#include <iostream>

using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        int l, r;
        int cont = 0;
        cin >> l;

        while(1){
            cin >> r;

            if(r == 0){
                break;
            }

            if(r > l*2){
                cont += r - (l*2);
            }
        
            l = r;
        }

        cout << cont << endl;
    }
}
