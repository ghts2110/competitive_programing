#include <iostream>

using namespace std;

int main(){
    int t;
    cin >> t;

    int cont = 0;
    while(t--){
        int num;
        cin >> num;

        if(num < 0){
            cont++;
        }
    }

    cout << cont << endl;
}
