#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        double n;
        cin >> n;
   
        cout << int ((sqrt((n*8)+1)-1)/2) << endl;
    }
}
