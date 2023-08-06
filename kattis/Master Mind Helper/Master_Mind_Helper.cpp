#include <iostream>
#include <string>
#include <vector>
#include <bitset>
#include <cmath>

#define pb push_back

using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        string s;
        int x, y;
        cin >> s >> x >> y;
        
        int num, limit = 1;
        for(int i = 0; i != s.size(); i++){
            limit*=10;
        }
        num = limit/10;
        
        int value = 0;
        while(num != limit){
            int contx = 0, conty = 0;
            bool validate = false;
            num++;
            
            string save = s, comp = to_string(num);        
            for(int i = 0; i != s.size(); i++){
                if(comp[i] == '0'){
                    validate = true;
                    break;
                }
            }
            if(validate){
                continue;
            }

            for(int i = 0; i != s.size(); i++){
                if(save[i] == comp[i]){
                    save[i] = comp[i] = '0';
                    contx++;
                }
            }

            for(char i : comp){
                if(i != '0'){
                    for(int j = 0; j != s.size(); j++){
                        if(i == save[j]){
                            conty++;
                            i = save[j] = '0';
                            break;
                        }
                    } 
                }
            }

            if(contx == x && conty == y){
                value++;
            }
        }

        cout << value << endl;
    }
}
