#include <iostream>

using namespace std;

int main(){
    int n;
    while(cin >> n){
        if(n == 0){
            break;
        }

        int cont = 0;

        while(n > 1){
            cont++;
            n /= 2;
        }

        cout << cont << endl;
    }
}
