#include <iostream>
#include <vector>
#include <string>

#define pb push_back

using namespace std;

int main(){
    string s;

    while(getline(cin, s)){
        if(s == "Game Over"){
            break;
        }

        int vl = 0, limit = 0;
        for(int i = 0 ; i != s.size(); i++){
            if(s[i] == ' '){
                s.erase(s.begin()+i);
                i--;
            }else{
                if(s[i] == 'X'){
                    vl+=2;
                }else{
                    vl++;
                }

                if(vl == 20){
                    limit = i;
                }
            }
        }

        bool validate = false;
        if(vl > 20){
            validate = true;
        }

        int cont = 0;
        vector<int> v(s.size());
        for(int i = s.size()-1; i != -1; i--){
            if(s[i] == '/'){
                if(i <= limit){
                    cont += 10 + v[i+1];
                    v[i] = 10;
                    cont -= s[i-1]-'0';
                }else{
                    v[i] = 10;
                }
            }else if(s[i] == 'X'){
                if(i > limit){
                    v[i] = 10;
                }else if(s[i+2] == '/'){
                    cont += 20;
                    v[i] = 10;
                }else{
                    cont += 10 + v[i+1] + v[i+2];
                    v[i] = 10;
                }
            }else{
                if(i <= limit){
                    cont += s[i]-'0';
                    v[i] = s[i]-'0';
                }else{
                     v[i] = s[i]-'0';
                }
            }
        }

        cout << cont << endl;
    }
}
