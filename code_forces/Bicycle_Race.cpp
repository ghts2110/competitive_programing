#include <iostream>

using namespace std;

int main(){
    int n, x1, y1, x2, y2, cont = 0;
    char c1 = 'T', c2;
    cin >> n;
    
    cin >> x1 >> y1;

    while(n--){
       cin >> x2 >> y2;

       if(y1 < y2){
            c2 = 'T';
       }else if(y1 > y2){
            c2 = 'D';
       }else if(x1 < x2){
            c2 = 'R';
       }else{
            c2 = 'L';
       }

       if((c1 == 'R' && c2 == 'T') || (c1 == 'L' && c2 == 'D') || (c1 == 'T' && c2 == 'L') || (c1 == 'D' && c2 == 'R')){
           cont++;
       }

       x1 = x2;
       y1 = y2;
       c1 = c2;
    }
    
    cout << cont << endl;
}
