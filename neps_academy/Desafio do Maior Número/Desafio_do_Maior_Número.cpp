#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int mx = 0;
    
    while(1){
        int n;
        cin >> n;

        if(n == 0){
            break;
        }

        mx = max(mx, n);
    }

    cout << mx << endl;
        
}
