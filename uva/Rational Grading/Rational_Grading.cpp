#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main(){
    string v;
    int t;
    while(cin >> v >> t){
        if(v=="0"){
            break;
        }

        int num = 0;
        if(v[0] == '0' && v[1] == 'x'){
            int p = 0;
            for(int i = v.size()-1; i != 1; i--){
                if(v[i] >= 'A'){
                    num += pow(16, p) * ((v[i]-'A')+10);
                }else{
                    num += pow(16, p) * (v[i]-'0');
                }
                p++;
            }
        }else if(v[0] == '0'){
            int p = 0;
            for(int i = v.size()-1; i != 0; i--){
                num += pow(8, p) * (v[i]-'0');
                p++;
            }
        }else{
            num = stoi(v);
        }
        
        int cont = 0;
        for(int i = 0; i != t; i ++){
            string s;
            int asw;
            
            cin >> s >> asw;
            if(s=="i"){
                if(asw == num){
                    cont++;
                }else{
                    num = asw;
                }
            }else if(s =="++i"){
                num++;
                if(asw == num){
                    cont++;
                }else{
                    num = asw;
                }
            }else if(s == "--i"){
                num--;
                if(asw == num){
                    cont++;
                }else{
                    num = asw;
                }
            }else if(s == "i++"){
                if(asw == num){
                    num++;
                    cont++;
                }else{
                    num = asw+1;
                }
            }else{
                if(asw == num){
                    num--;
                    cont++;
                }else{
                    num = asw-1;
                }
            }
        }

        cout << cont << endl;
    }
}
