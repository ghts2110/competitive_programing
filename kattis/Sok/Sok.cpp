#include <iostream>
#include <cmath>

using namespace std;

int main(){
    double a, b, c;
    while(cin >> a >> b >> c){
        double d, e, f;
        cin >> d >> e >> f;

        double mn = min(a/d, b/e);
        mn = min(mn, c/f);

        printf("%.4f %.4f %.4f\n", a - (mn * d), b - (mn * e), c - (mn * f));
    }
}
