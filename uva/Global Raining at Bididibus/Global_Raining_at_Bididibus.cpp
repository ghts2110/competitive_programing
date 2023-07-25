#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        string s;
        cin >> s;

        int sum = 0;
        for(int i = 0; i != s.size(); i++){
            if(s[i] == '/'){
                int cont = 0;
                for(int j = i; j != -1; j--){
                    if(j == 0 && (s[j] == '/' || s[j] == '_')){
                        s.erase(s.begin() + i);
                        i--;
                    }else if(s[j] != '/' && s[j] != '_'){
                        s[j] = '_';
                        sum += cont;
                        break;
                    }

                    cont++;
                }
            }
        }

        cout << sum << endl;;
        
    }
}
