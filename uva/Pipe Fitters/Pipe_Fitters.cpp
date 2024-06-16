#include <iostream>
#include <cmath>

using namespace std;

int calc(double a, double b)
{
    int col = int(b);
    int row = 1 + (2/sqrt(3.0))*(a-1);
    int asw = row * col;
    if(b - int(b) < 0.5){
        asw -= row/2;
    }
    return asw;
}

int main(){
    double n, m;
    while(cin >> n >> m){
        int g = 0, s = 0;
        g = int(n) * int(m);
        s = max(calc(n, m), calc(m, n));

        if(g >= s){
            cout << g << " grid" << endl;
        }else{
            cout << s << " skew" << endl;
        }
    }
}
