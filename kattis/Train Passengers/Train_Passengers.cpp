#include <iostream>

using namespace std;

int main(){
    int cap, n;
    while(cin >> cap >> n){
        bool validate = true;
        long long  cont = 0;
        long long a, b, c;
        for(int i = 0; i != n; i++){
            cin >> a >> b >> c;
            cont -= a;
            if(cont < 0){
                validate = false;
            }

            cont += b;
            if(cont > cap){
                validate = false;
            }

            if(cont != cap && c != 0){
                validate = false;
            }
        }
        if(cont != 0 || c != 0){
            validate  = false;
        }

        if(validate){
            cout << "possible" << endl;
        }else{
            cout << "impossible" << endl;
        }
    }
}
