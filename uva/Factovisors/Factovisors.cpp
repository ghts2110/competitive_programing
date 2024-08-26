#include <iostream>

using namespace std;

bool phi(int m, int n){
    bool b = true;
    for(long long i = 2; i * i <= m; i++){
        if(m % i == 0){
            int cont = 0;
            while(m % i == 0){
                cont++;
                m /= i;
            }
            int cont2 = 0;
            for(long long j = i; j <= n; j *= i){
                cont2 += n/j;
            }
            if(cont > cont2){
                b = false;
                break;
            }
        }
    }
    if(m > 1){
       if(1 > n/m){
            b = false;
        } 
    }
    return b;
}

int main(){
    int n, m;

    while(cin >> n >> m){
        bool r = phi(m, n);
        if(r){
            cout << m << " divides " << n << "!" << "\n"; 
        }
        else{
            cout << m << " does not divide " << n << "!" << "\n";
        }
    }
}
