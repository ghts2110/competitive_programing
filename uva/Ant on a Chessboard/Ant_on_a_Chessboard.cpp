#include <iostream>

using namespace std;

int main(){
    long long n;
    while(cin >> n){
        if(n == 0){
            break;
        }

        long long lc = 0;
        for(long long i = 1; i * i <= n; i++){
            lc = i; 
        }
        if(lc * lc != n){
            lc++;
        }

        long long dif = lc*lc-n;
        
        int l, c;
        if(lc%2==1){
            if(dif >= lc){
                c = lc;
                l = lc-(dif-lc+1);
            }else{
                c = dif+1;
                l = lc;
            }
        }else{
            if(dif >= lc){
                c = lc-(dif-lc+1);
                l = lc;
            }else{
                c = lc;
                l = dif+1;
            }
        }

        cout << c << ' ' << l << endl;
    }
}
