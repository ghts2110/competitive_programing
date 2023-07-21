#include <iostream>

using namespace std;

int main(){
    int t;
    while(cin >> t){
        int n, cont = 0;
    
        for(int i = 0; i != 5; i++){
            cin >> n;
            if(n == t){
                cont++;
            }
        }

        cout << cont << endl;
    }
}
