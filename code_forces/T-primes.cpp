#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        long long num;
        scanf("%lld", &num);

        if(num == 1 || num == 0){
            printf("NO\n");
            continue;
        }

        double f = sqrt(num);
        long long in = sqrt(num);

        if(f == in){
            num = sqrt(num);
            int cont = 0;
            for(int i = 2; i <= sqrt(num); i++){
               if(num % i == 0){
                    cont++;
                    break;
               }
            }
            
            if(cont == 1){
                printf("NO\n");
            }else{
                printf("YES\n");
            }
        }else{
            printf("NO\n");
        }

    }
}
