#include <iostream>

using namespace std;

int main(){
    double x, y;
    cin >> x;
    
    int comp = x = x*1000.0*5280.0 / 4854.0;
    if(int(x*10)%10 >= 5){
        comp++;
    }

    cout << comp << endl;
}
