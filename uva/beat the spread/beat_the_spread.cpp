#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int test;
    cin >> test;

    while(test--){
        double s,d;
        cin >> s >> d;

        long long a1  = (d + s)/2;
        long long b1 = s - a1;
        
        double a2 = (d + s)/2;
        double b2 = s - a1;

        if(a1 < 0 || b1 < 0 || a1 != a2 || b1 != b2){
            cout << "impossible" << endl;
        }else{
            if(a1 > b1){
                cout << a1 <<" " << b1 << endl;
            }else{
                cout << b1 << " " << a1 << endl;
            }
        }
    }
}
