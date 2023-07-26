#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main(){
    string s;
    double val = 0;
    int cont = 0;
    
    while(cin >> s){
        if(s == "buy"){
            int x, y;
            cin >> x >> y;
            
            val = ((cont * val) + (x * y)) / (cont + x);
            cont += x;
        }else if(s == "split"){
            int x;
            cin >> x;
        
            cont *= x;
            val /= x;
        }else if(s == "merge"){
            int x;
            cin >> x;

            cont /= x;
            val *= x;
        }else if(s == "sell"){
            int x, y;
            cin >> x >> y;

            cont -= x;
        }else{
            double y;
            cin >> y;

            printf("%.3f\n", cont * (y - (0.3 * max(y-val, 0.0))));
            cont = val = 0;
        }
    }
}
