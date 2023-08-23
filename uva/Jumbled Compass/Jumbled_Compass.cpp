#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int n1, n2;
    while(cin >> n1 >> n2){
        int a = (360-n1)+n2, b = n1+(360-n2), c = abs(n1-n2);
        int mn = min(a, min(b, c));
        if((mn == b || (mn == c && n1 > n2)) && mn != 180){
            mn *= -1;
        }

        cout << mn << endl;
    }
}
