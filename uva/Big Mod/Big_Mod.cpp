#include <iostream>
#include <vector>

using namespace std;

vector<long long> v;

long long modulo(long long b, long long p, long long m){
    if(p == 1){
        return b%m;
    }

    if(b < m){
        if(p % 2 == 1){
            v.push_back(b);
        }
        return modulo(b * b, p/2, m);
    }

    return modulo(b % m, p, m);
}
int main(){
    long long b, p, m;

    while(scanf("%lld %lld %lld", &b, &p, &m) == 3){
    
        if(p == 0){
            p = 1;
            b = 1;
        }

        v.clear();
        long long num = modulo(b, p, m);     
        for(int i = 0; i != v.size(); i++){
            num *= v[i];
            num %= m;
        }

        printf("%lld\n", num%m);
    }
}
