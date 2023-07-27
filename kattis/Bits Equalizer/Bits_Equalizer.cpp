#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main(){
    string s, t;
    int n;
    cin >> n;

    int c = 1;
    while(n--){
        cout << "Case "<<c<<": ";
        c++;

        cin >> s >> t;
           
        int move = 0;
        for(int i = 0; i != s.size(); i++){
            if(s[i] == '0' && t[i] == '1'){
                int index = -1;
                for(int j = 0; j != s.size(); j++){
                    if(s[j] == '1' && t[j] == '0'){
                        index = j;
                        break;
                    }
                }

                if(index == -1){
                    s[i] = '1';
                }else{
                    s[i] = '1';
                    s[index] = '0';
                }

                move++;
            }
        }

        for(int i = 0; i != s.size(); i++){
            if(s[i] == '1' && t[i] == '0'){
                int index = -1;
                for(int j = 0; j != s.size(); j++){
                    if(s[j] == '?' && t[j] == '1'){
                        index = j;
                        break;
                    } 
                }

                if(index == -1){
                    move = -1;
                    break;
                }else{
                    s[i] = '0';
                    s[index] = t[index];
                }
                move += 2;
            }
        }
        
        if(move == -1){
            cout << move << endl;
            continue;

        }
        for(int i = 0; i != s.size(); i++){
            if(s[i] == '?'){
                move++;
            }
        }

        cout << move << endl;
    }
}
