#include <iostream>
#include <string>

using namespace std;

int main(){
    string s;
    while(cin >> s){
        int cont = 0;
        for(auto it : s){
            if(it >= 'a'){
                cont += it-'a'+1;
            }else{
                cont += it-'A'+27;
            }
        }

        bool p = true;
        for(int i = 2; i*i <= cont; i++){
            if(cont % i == 0){
                p = false;
                break;
            }
        }

        if(p){
            cout << "It is a prime word." << endl;
        }else{
            cout << "It is not a prime word." << endl;
        }
    }
}
