#include <iostream>

using namespace std;

long long gcd(long long a, long long b){
    if(b == 0){
        return a;
    }

    long long t = b;
    b = a%b;
    a = t;
    return gcd(a, b);
}

int main(){
    long long n, m, q;
    cin >> n >> m >> q;

    long long g = gcd(n, m);
  
    while(q--){
        long long x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        if(g == 1){
            cout << "YES" << endl;
            continue;
        }

        y1--;
        y2--;
        long long grupoXY1, grupoXY2;
        if(x1 == 1){
            grupoXY1  = y1/(n/g);
        }else{
            grupoXY1 = y1/(m/g);
        }

        if(x2 == 1){
            grupoXY2  = y2/(n/g);
        }else{
            grupoXY2 = y2/(m/g);
        }

        if(grupoXY1 == grupoXY2){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
}
