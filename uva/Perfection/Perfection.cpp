#include <iostream>

using namespace std;

int main(){
    int n;
    cout << "PERFECTION OUTPUT" << endl;
    while(cin >> n){
        if(n==0){
            break;
        }

        long long cont = 1;
        
        if(n == 1){
            cont = 0;
        }

        for(long long i = 2; i * i <= n; i++){
            if(n%i==0){
                cont+=i;
                if(i != n/i){
                    cont += n/i;
                }
            }
        }

        if(cont == n){
            printf("%5d  PERFECT\n", n);
        }else if(cont > n){
            printf("%5d  ABUNDANT\n", n);
        }else{
            printf("%5d  DEFICIENT\n", n);
        }
    }

    cout << "END OF OUTPUT" << endl;
}
