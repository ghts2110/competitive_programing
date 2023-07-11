#include <iostream>
#include <cmath>

using namespace std;

int main(){
    long long n, k;
    cin >> n >> k;
    
    long long v = 0;
    for(long long i = 1; i <= 2*n; i++){
        long long v2 = (i*i) - k;
        
        if(v2 < 0){
            v2 *= -1;
        }

        if(v2 % ((2*n)+1) == 0){
            if(i * i != k){
                v = i*i;
            }
        }
    }

    cout << v << endl;
}
