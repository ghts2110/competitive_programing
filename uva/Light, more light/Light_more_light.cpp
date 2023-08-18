#include <iostream>
#include <cmath>

using namespace std;

int main(){
    long long n;
    
    while(scanf("%lld", &n)){
        
        if(n == 0){
            break;
        }
        
        double d = sqrt(n);
        int nt = sqrt(n);


        if(d != nt){
            printf("no\n");
        }else{
            printf("yes\n");
        }
    }
}
