#include <iostream>
#include <string>

using namespace std;

int main(){
    string s;
    cin >> s;

    int cont = 0;

    for(int i = 1; i != s.size(); i++){
        if(i == 1 && s[i] != s[i-1]){
            cont++;
            if(s[i] == 'D'){
                cont++;
            }
            continue;
        }else if(i == 1){
            if(s[i] == 'D'){
                cont++;
            }
            continue;
        }

        if(s[i] == 'D'){
            cont += 2;
        }
    }

    cout << cont << endl;
    cont = 0;

    for(int i = 1; i != s.size(); i++){
        if(i == 1 && s[i] != s[i-1]){
            cont++;
            if(s[i] == 'U'){
                cont++;
            }
            continue;
        }else if(i == 1){
            if(s[i] == 'U'){
                cont++;
            }
            continue;
        }

        if(s[i] == 'U'){
            cont += 2;
        }
    }
    
    cout << cont << endl;
    cont = 0;

    for(int i = 1; i != s.size(); i++){
        if(s[i] != s[i-1]){
            cont++;
        }
    }
    cout << cont << endl;
}
