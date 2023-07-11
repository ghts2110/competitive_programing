#include <iostream>

using namespace std;

int main(){
    int t, cont = 0, n;
    cin >> t;

    while(t--){ 
        cin >> n;
        if(n != 1){
            cont++;
        }
    }


    cout << cont << endl;
}
