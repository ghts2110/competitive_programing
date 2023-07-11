#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int n;

    while(cin >> n && n != 0){
        int cont = 0;
        for(int i = 2; i != n + 1; i++){
            if(n % i == 0){
                int isp = 1;
                for(int j = 2; j <= sqrt(i); j++){
                    if(i % j == 0){
                        isp = 0;
                        break;
                    }            
                }

                if(isp == 1){
                    cont++;
                }
            }
        }

        printf("%d : %d\n", n, cont);
    }
}
