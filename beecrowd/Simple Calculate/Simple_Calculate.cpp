#include <iostream>

using namespace std;

int main(){
    float cont = 0;
    int cod, unit;
    float p;
    for(int i = 0; i != 2; i++){
        cin >> cod >> unit >> p;

        cont += unit*p; 
    }

    printf("VALOR A PAGAR: R$ %.2f\n", cont);
}
