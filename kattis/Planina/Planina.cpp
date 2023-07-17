#include <iostream>
#include <cmath>

using namespace std;

int main(){
    long long n;
    cin >> n;

    long long cont = 1;
    for(int i = 0; i != n; i++){
        cont *= 2;
    }
   
    cont++;
    cout << cont * cont << endl;
}
