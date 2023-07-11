#include <iostream>

using namespace std;

int main(){
    int a, b, cont = 0;

    cin >> a >> b;

    while(a <= b){
        cont++; 
        a *= 3;
        b *= 2;
    }

    cout << cont <<endl;
}
