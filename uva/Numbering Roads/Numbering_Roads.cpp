#include <iostream>

using namespace std;

int main(){
    int a, b;
    int t = 1;
    while(1){
        cin >> a >> b;
        if(a == 0 && b == 0){
            break;
        }

        cout << "Case "<< t <<": ";
        t++;

        int cont = 0;
        cont += a/b;
        if(a%b != 0){
            cont++;
        }

        if(cont > 27){
            cout << "impossible" << endl;
            continue;
        }

        cout << cont -1 << endl;
    }
}
