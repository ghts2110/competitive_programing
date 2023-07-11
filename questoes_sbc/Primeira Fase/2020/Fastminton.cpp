#include <iostream>
#include <string>

using namespace std;

int main(){
    string s;
    getline(cin, s);

    int i, sac = 0, d = 0, e = 0, gd = 0, ge = 0;
    for(i = 0; i != s.size(); i++){
        if(sac == 0 && s[i] == 'S'){
            e++;
        }else if(sac == 0 && s[i] == 'R'){
            d++;
            sac = 1;
        }else if(sac == 1 && s[i] == 'S'){
            d++;
        }else if(sac == 1 && s[i] == 'R'){
            e++;
            sac = 0;
        }else{
            if(gd != 2 && ge != 2){
                if(sac == 0){
                    cout << ge << " (" << e << "*) - " << gd << " (" << d << ")" << endl; 
                }else{
                    cout << ge << " (" << e << ") - " << gd << " (" << d << "*)" << endl; 
                }
            }else{
                if(ge == 2){
                    cout << ge << " (winner) - " << gd << endl;
                }else{
                    cout << ge << " - " << gd << " (winner)" << endl;
                }
            }
        }


            
        if((d >= 5 && d - e >= 2) || d == 10){
            gd++;
            d = 0;
            e = 0;
        }else if((e >= 5 && e - d >= 2)|| e == 10){
            ge++;
            d = 0;
            e = 0;
        }
    }
}
