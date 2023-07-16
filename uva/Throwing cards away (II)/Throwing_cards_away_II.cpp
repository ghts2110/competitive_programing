#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int n;
    while(true){
        cin >> n;

        if(n == 0){
            break;
        }

        int x = 0;
        for(int i = 0; i <= 19; i++){
            if(pow(2, i) >= n){
                x = i-1;
                break;
            }
        }

        cout << (n-pow(2, x))*2 << endl;
    }
}
