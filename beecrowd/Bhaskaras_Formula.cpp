#include <iostream>
#include <cmath>

using namespace std;

int main(){
    double a, b, c;
    cin >> a >> b >> c;

    double del = b*b - (4*a*c);

    if(del < 0 || a == 0){
        cout << "Impossivel calcular" << endl;
        return 0;
    }

    printf("R1 = %.5f\n", (-b + sqrt(del))/(2*a));
    printf("R2 = %.5f\n", (-b - sqrt(del))/(2*a));
}
