#include <iostream>
#include <string>

using namespace std;

int main(){
    string s;
    while(getline(cin, s)){
        int cont = 0;
        for(auto it : s){
            if(isdigit(it)){
                cont += it-'0';
                continue;
            }
            if(it == '!'){
                cout << endl;
                continue;
            }
            
            if(it == 'b'){
                it = ' ';
            }
            for(int i = 0; i != cont; i++){
                cout << it;
            }
            cont = 0;
        }
        cout << endl;
    }
}
