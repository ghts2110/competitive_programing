#include <iostream>

using namespace std;

int main(){
    int t;
    while(1){
        cin >> t;

        if(t == 0){
            break;
        }

        int cont = 0;
        bool isPrime = true;
        for(int i = 2; i <= t/2; i++){
            isPrime = true;
            for(int j = 2; j * j <= i; j++){
                if(i % j == 0){
                    isPrime = false;
                    break;
                }
            }

            if(t-i <= 1 ){
                isPrime = false;
            }

            if(isPrime){
                for(int j = 2; j * j <= t-i; j++){
                    if((t-i) % j == 0){
                        isPrime = false;
                    }
                }
            }

            if(isPrime){
                cont ++;
            }
        }

        cout << cont << endl;
    }
}
