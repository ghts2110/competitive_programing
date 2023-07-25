#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main(){
    int t;
    while(cin >> t){
        if(t==0){
            break;
        }

        string s;
        cin >> s;

        int cont = 0, mn = 1e9, l = -1;
        for(int i =0 ;i != t;i++){
            if(s[i] == 'Z'){
                mn = 0;
                break;
            }

            if(l == -1 && (s[i] == 'R' || s[i] == 'D')){
                if(s[i] == 'R'){
                    l = 0;
                }else{
                    l = 1;
                }
            }
            
            if(l == 0 && s[i] == 'D'){
                mn = min(mn, cont);
                l = 1;
                cont = 0;
            }else if(l == 1 && s[i] == 'R'){
                 mn = min(mn, cont);
                 l = 0;
                 cont = 0;
            }else if(l == 1 && s[i] == 'D'){
                cont = 0;
            }else if(l == 0 && s[i] == 'R'){
                cont = 0;
            }

            if(l != -1){
                cont++;
            }
        }

        cout << mn << endl;
    }
}
