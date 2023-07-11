#include <iostream>
#include <vector>
#include <stdio.h>
#include <string.h>

using namespace std;

    
char s[1000000000];

int main(){

    int cont = 0;
    while(gets(s)){

        for(int i = 0; i < strlen(s); i++){
            if(s[i] == '"'){
                if(cont == 0){
                    cout << "``";
                    cont = 1;
                }else{
                    cout << "''";
                    cont = 0;
                }
            }else{
                cout << s[i];
            }
        }
        
        cout << endl;
    }
}
