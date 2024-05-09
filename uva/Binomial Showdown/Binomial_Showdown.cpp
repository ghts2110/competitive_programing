#include <iostream>

using namespace std;

int main(){
    int n, k;
    while(cin >> n >> k){
        if(!n && !k){
            break;
        }

        double asw = 1;
        if(n-k > k){
            for(int i = n; i > n-k; i--){
                asw *= i;
            }
            for(int i = 2; i <= k; i++){
                asw /= i;
            }
        }else{
            for(int i = n; i > k; i--){
                asw *= i;
            }
            for(int i = 2; i <= n-k; i++){
                asw /= i;
            }
        }
        
        printf("%lld\n", (long long)asw);
    }
}
