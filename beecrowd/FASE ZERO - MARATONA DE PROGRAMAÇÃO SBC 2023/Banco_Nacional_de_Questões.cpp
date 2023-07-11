#include <iostream>

using namespace std;

int main(){
    long double a, b, c;
    char s;
    cin >> a >> b >> c;
    cin >> s;

    long double cont = 0;
    if(s == 'A'){
        cont +=  (5 * c)/2;
        cont +=  (3 * b)/2;

        cont += a;
    }else if(s == 'B'){
        cont +=  (5 * c) / 3;
        cont +=  (2 * a) / 3;
        
        cont += b;
    }else{
        cont +=  (2 * a)/5;
        cont += (3 * b)/5;

        cont += c;
    }

    cout << (long long)cont << endl;
}
