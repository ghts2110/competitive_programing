#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int l, r;
    cin >> l >> r;

    int mx = max(l, r);
        
    if(mx == 0){
        cout << "Not a moose" << endl;
        return 0;
    }
    if(l == r){
        cout << "Even " << mx * 2<< endl;
        return 0;
    }


    cout << "Odd " << mx * 2 << endl;
}
