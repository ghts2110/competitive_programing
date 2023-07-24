#include <iostream>

using namespace std;

int main(){
    int t;
    cin >> t;

    int cont = 1;
    while(t--){
        cout << "Case "<<cont<<": ";
        cont++;

        int n;
        cin >> n;

        char c;
        int cont = 0;
        int p = 0;
        for(int i = 0; i != n; i++){
            cin >> c;

            if(c != 'W'){
                cont++;
            }else{
                cont = 0;
            }

            if(cont == 3 && p == 0){
                p = i+1;
            }
        }

        if(p == 0){
            cout << "Yay! Mighty Rafa persists!" << endl;
        }else{
            cout << p << endl;
        }
    }
}
