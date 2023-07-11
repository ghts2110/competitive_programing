#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        int num;
        cin >> num;

        int cont = 0;
        while((cont * (cont +1))/2 < num){
            cont++;
        }

        if((cont * (cont +1))/2 == num){
            cout << cont << endl;
        }else{
            cout << cont-1 << endl;
        }
    }
    
}
