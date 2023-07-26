#include <iostream>

using namespace std;

int main(){
    int t;
    while(cin >> t){
        int cont = 1;
        
        bool validate = true;
        while(t--){
            int num;
            cin >> num;

            while(cont != num){
                validate = false;
                cout << cont << endl;
                cont++;
            }
            cont++;
        }

        if(validate){
            cout << "good job" << endl;
        }
    }
}
