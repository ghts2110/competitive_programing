#include <iostream>

using namespace std;

int main(){
    int t;
    cin >> t;
    
    bool f = true;
    while(t--){
        int p, q;
        cin >> p >> q;

        while(q--){
            if(!f){
                cout << endl;
            }
            f = false;

            int cont = 1;

            while(cont != p){
                for(int i = 0; i != cont; i++){
                    cout << cont;
                }
                cout << endl;
                cont++;
            }

            while(cont != 0){
                for(int i = 0; i != cont; i++){
                    cout << cont;
                }
                cout << endl;
                cont--;
            }
        }
    }
}
