#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int a1, a2, b1, b2;
    while(1){
        int p1, p2;
        cin >> a1 >> a2 >> b1 >> b2;
        
        if(a1 == 0){
            break;
        }

        if((a1 * 10) + a2 == 12 || (a1 * 10) + a2 == 21){
            p1 = 1000;
        }else if(a1 == a2){
            p1 = 100 * a1;
        }else{
            p1 = (max(a1, a2) * 10) + min(a1, a2);
        }

        if((b1 * 10) + b2 == 12 || (b1 * 10) + b2 == 21){
            p2 = 1000;
        }else if(b1 == b2){
            p2 = 100 * b1;
        }else{
            p2 = (max(b1, b2) * 10) + min(b1, b2);
        }

        if(p1 > p2){
            cout << "Player 1 wins." << endl;
        }else if(p1 < p2){
            cout << "Player 2 wins." << endl;
        }else{
            cout << "Tie." << endl;
        }
    }
}
