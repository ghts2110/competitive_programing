#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    cout << n << ":" << endl;

    int l = 2, r = 1, cont = 0;
    while(l < n){
        if(n%(l+r) == 0 || n%(l+r) == l){
            cout << l << "," << r << endl;
        }

        if(cont % 2 == 0){
            r++;
        }else{
            l++;
        }
            
        cont++;
    }
}
