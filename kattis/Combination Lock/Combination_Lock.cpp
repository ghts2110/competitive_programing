#include <iostream>

using namespace std;

int main(){
    int p, a, b, c;
    while(1){
        cin >> p >> a >> b >> c;
        
        if(!p && !a && !b && !c){
            break;
        }

        int cont = 1080;
        if(p >= a){
            cont += 9 * (p-a);
        }else{
            cont += 9*(40 - (a-p));
        }

        if(a > b){
            cont += 9*(40 - (a-b));
        }else{
            cont += 9 * (b-a);
        }

        if(b >= c){
            cont += 9 * (b-c);
        }else{
            cont += 9*(40 - (c - b));
        }

        cout << cont << endl;

    }
}
