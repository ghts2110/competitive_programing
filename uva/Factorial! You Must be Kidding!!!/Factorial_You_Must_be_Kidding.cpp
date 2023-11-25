#include <iostream>
using namespace std;

long long factorial(long long n){
    if(n == 1){
        return 1;
    }
    return n * factorial(n-1);
}

int main(){
    long long n;
    while(cin >> n){
        long long pos = abs(n);
        bool ispar = false;
        if(pos % 2 == 0){
            ispar = true;
        }
        if((n == pos && n < 8) || (n != pos && ispar)){
            cout << "Underflow!" << endl;
        }else if(( n == pos && n > 13) || (n != pos && !ispar)){
            cout << "Overflow!" << endl;
        }else{
            cout << factorial(n) << endl;
        }
    }
}