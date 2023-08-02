#include <iostream>

using namespace std;

int main(){
    int a, b, c;
    while(cin >> a >> b >> c){
        if(a == b){
            cout << "Illegal state" << endl;
            continue;
        }
        if(c == b){
            cout << "Illegal move" << endl;
            continue;
        } 
        
        int sl = b - (b%8), fl = b + 7-(b%8);
        if(c >= sl && c <= fl && ((a>=c && a<=b) || (a>=b && a<=c))){
            cout << "Illegal move" << endl;
            continue;
        }

        if(b%8 != c%8 && (c < sl || c > fl)){
            cout << "Illegal move" << endl;
            continue;
        }

        if(a%8 == b%8 && ((a>=c && a<=b) || (a>=b && a<=c))){
            cout << "Illegal move" << endl;
            continue;
        }

        if((c == a-1 && a%8 != 0) || (c == a+1 && a%8 != 7) || c == a+8 || c == a-8){
            cout << "Move not allowed" << endl;
        }else if((c == a+9 || c == a+7 || c == a-7 || c == a-9) && (a == 0||a == 56||a == 7||a == 63)){
            cout << "Stop" << endl;
        }else{
            cout << "Continue" << endl;
        }

    }
}
