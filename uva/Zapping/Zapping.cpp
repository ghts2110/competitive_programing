#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int a, b;
    while(1){
        cin >> a >> b;
        if(a == -1 && b == -1){
            break;
        }

        int mn = min(abs(a - b), min(a,b) + 100-max(a, b));
        cout << mn << endl;
    }
}
