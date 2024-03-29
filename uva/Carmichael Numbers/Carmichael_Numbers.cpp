#include <iostream>

using namespace std;
typedef long long ll;

int main(){
    int n;

    while(cin >> n){

        if(!n){
            break;
        }

        bool p = true;
        for(int i = 2; i*i <= n; i++){
            if(n % i == 0){
                p = false;
                break;
            }
        }

        if(p){
            cout << n << " is normal." << endl;
            continue;
        }else{
            p = true;
            for(int i = 2; i <= n-1 && p; i++){
                ll pow = n;
                ll a = i, asw = 1;;
                
                while(pow){
                    if(pow % 2 == 0){
                        a *= a;
                        a %= n;
                        pow /= 2;
                    }else{
                        asw *= a;
                        asw %= n;
                        pow--;
                    }
                }

                if(asw%n != i){
                    p = false;
                    break;
                }
            }

        }


        if(!p){
            cout << n << " is normal." << endl;
        }else{
            cout << "The number "<< n <<" is a Carmichael number." << endl;
        }

    }
}
