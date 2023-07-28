#include <iostream>

using namespace std;

int main(){
    double h, u, d, f;
    while(cin >> h >> u >> d >> f){
        if(h == 0){
            break;
        }

        double cont = 0, dy = 0;
        f = u * f /100;
        while(1){
            dy++;
            cont += u;
            if(cont > h){
                cout << "success on day " << dy << endl;
                break;
            }
            cont -= d;
            u -= f;
            if(u < 0){
                u = 0;
            }
            if(cont < 0){
                cout << "failure on day " << dy << endl;
                break;
            }
        }
    }
}
