#include <iostream>

using namespace std;

int main(){
    int t;
    cin >> t; 

    while(t--){
        int x, y, n1, n2;
        cin >> n1 >> n2;
        x = (n1+n2)/2;
        y = n1-x;

        if(y < 0 || x+y != n1 || x-y != n2){
            cout << "impossible" << endl;
        }else{
            cout << x << " " << y << endl;
        }
    }
}
