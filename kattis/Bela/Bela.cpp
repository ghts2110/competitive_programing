#include <iostream>
#include <string>

using namespace std;

int main(){
    int n;
    char b;

    while(cin >> n >> b){
        int cont = 0;
        for(int i = 0;i  != n*4; i++){
            string s;
            cin >> s;

            if(s[1] == b){
                if(s[0] == 'A'){
                    cont += 11;
                }else if(s[0] == 'K'){
                    cont += 4;
                }else if(s[0] == 'Q'){
                    cont += 3;
                }else if(s[0] == 'J'){
                    cont += 20;
                }else if(s[0] == 'T'){
                    cont += 10;
                }else if(s[0] == '9'){
                    cont += 14;
                }
            }else{
                if(s[0] == 'A'){
                    cont += 11;
                }else if(s[0] == 'K'){
                    cont += 4;
                }else if(s[0] == 'Q'){
                    cont += 3;
                }else if(s[0] == 'J'){
                    cont += 2;
                }else if(s[0] == 'T'){
                    cont += 10;
                }

            }
        }

        cout << cont << endl;
    }
}
