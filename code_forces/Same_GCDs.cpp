#include <iostream>

using namespace std;

long long gcd(long long a, long long b){
    if(b == 0){
        return a;
    }

    return gcd(b, a%b);
}

long long phi(long long m){
    long long value = m;
    for(long long i = 2; i * i <= m; i++){
        if(m % i == 0){
            while(m % i == 0){
                m /= i;
            }

            value *= (1.0 - (1.0/(float)i));
        }    
    }

    if(m > 1){
        value -= value/m;
    }

    return value;
}

int main(){
    int t;
    cin >> t;

    while(t--){
        long long a, m;
        cin >> a >> m;

        cout << phi(m/gcd(m - a, a)) << endl;
    }
}
