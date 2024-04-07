#include <iostream>

using namespace std;

int main(){
    int n, k;
    while(cin >> n >> k){
        int asw = n;
        while(n/k != 0){
            asw += (n/k);
            n = (n%k) + (n/k);
        }

        cout << asw << endl;
    }
}
