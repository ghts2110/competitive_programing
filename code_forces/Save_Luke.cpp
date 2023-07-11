#include <iostream>

using namespace std;

int main(){
    double d, l, v1, v2;
    double cont = 0;
    
    cin >> d >> l >> v1 >> v2;
       
    cont = (l-d)/(v1+v2);

    printf("%.6f\n", cont);
}
