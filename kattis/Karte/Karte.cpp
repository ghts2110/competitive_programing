#include <iostream>
#include <string>
#include <bitset>

using namespace std;

int main(){
    string s;
    while(cin >> s){
        int p = 0, k = 0, h = 0, t = 0;
        bitset<14> btp(0), btk(0), bth(0), btt(0);
        bool validate = true;

        for(int i = 0; i != s.size(); i+=3){
            int num;
            if(s[i] == 'P'){
                p++;
                num = (s[i+1]-'0')*10 + (s[i+2]-'0');
                if(btp[num] == 1){
                    validate = false;
                }
                btp[num] = 1;

            }else if(s[i] == 'K'){
                k++;
                num = (s[i+1]-'0')*10 + (s[i+2]-'0');
                if(btk[num] == 1){
                    validate = false;
                }
                btk[num] = 1;

            }else if(s[i] == 'H'){
                h++;
                num = (s[i+1]-'0')*10 + (s[i+2]-'0');
                if(bth[num] == 1){
                    validate = false;
                }
                bth[num] = 1;

            }else{
                t++;
                num = (s[i+1]-'0')*10 + (s[i+2]-'0');
                if(btt[num] == 1){
                    validate = false;
                }
                btt[num] = 1;

            }
        }

        if(validate){
            cout << 13-p << " " << 13-k << " " << 13-h << " " << 13-t << endl;
        }else{
            cout << "GRESKA" << endl;
        }
    }
}
