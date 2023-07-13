#include <iostream>

using namespace std;

int main(){
    int h, p, f, d;
    char s = 'S';

    cin >> h >> p >> f >> d;

    while(1){
        f += d;

        if(f == -1){
            f = 15;
        }else if(f == 16){
            f = 0;
        }

        if(p == f){
            s = 'N';
            break;
        }else if(h == f){
            break;
        }
    }
    
    cout << s << endl;
}
