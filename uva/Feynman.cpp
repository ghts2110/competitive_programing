#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int t;
    while(1){
        cin >> t;

        if(t == 0){
            break;
        }

        int cont = 0;
        for(int i = 0; i != t; i++){
            for(int j = 0; j != t; j++){
                cont += min(t-i, t- j);
            }
        }

        cout << cont << endl;
    }
}
