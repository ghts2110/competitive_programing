#include <iostream>

using namespace std;

int main(){
    long long n;
    while(cin >> n){
        if(n == 0){
            break;
        }
        cout << n << " = ";

        bool val = false;
        if(n <0){
            val = true;
            cout << -1;
            n *= -1;
        }

        for(long long i = 2; i*i <= n; i++){
            if(n%i == 0){
                while(n%i==0){
                    n/=i;

                    if(val){
                        cout << " x " << i;  
                    }else{
                        cout << i;
                    }
                    val = true;
                }
            }
        }

        if(n > 1){
            if(val){
                cout << " x " << n;
            }else{
                cout << n;
            }
        }

        cout << endl;
    }
}
