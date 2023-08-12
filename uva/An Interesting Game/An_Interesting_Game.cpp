#include <iostream>

using namespace std;

int main(){
    int t; 
    cin >> t;

    int test = 1;
    while(t--){
        int n, k, x;
        cin >> n >> k >> x;

        int cont = 0;
        for(int i = 0; i != n; i++){
            cont += i+1;
        }

        for(int i = x; i != k+x; i++){
            cont -= i;
        }

        cout << "Case "<<test<<": ";
        test++;
        cout << cont << endl;
    }
}
