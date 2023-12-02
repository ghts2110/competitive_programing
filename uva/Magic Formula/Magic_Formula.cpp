#include <iostream>
using namespace std;

int main(){
    double a,b,c,l;
    int d;
    while(true){
        cin >> a >> b >> c >> d >> l;
        if(a ==0 && b == 0 && c == 0 && d == 0){
            break;
        }

       double y;
        double cont = 0;
       for(int i = 0; i <= l; i++){
            y = (a * (i * i)) + (b * i) + c;
            int y_inte = (int)y;
            if(y == y_inte && y_inte % d == 0){
               cont++;
            }
       }

       cout << cont << endl;
    }
}