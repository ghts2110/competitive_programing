#include <iostream>
#include <cstring>

using namespace std;

int main(){
    int n;
    while(cin >> n){
        long long abc = 0, d = 1;
        for(int i = 0; i != n; i++){
            long long newABC = ((3*d)+(2*abc))%1000000007;
            long long newD = abc;

            abc = newABC;
            d = newD;
        }

        cout << d << endl;
    }
}