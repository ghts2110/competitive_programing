#include <iostream>
#include <string>

using namespace std;

int main(){
    int c[3];

    string s;
    while(cin >> s){
        c[0] = 1;
        c[1] = c[2] = 0;
    
        for(int i = 0; i != s.size(); i++){
            if(s[i] == 'A'){
                int save = c[0];
                c[0] = c[1];
                c[1] = save;
            }else if(s[i] == 'B'){
                int save = c[1];
                c[1] = c[2];
                c[2] = save;
            }else{
                int save = c[0];
                c[0] = c[2];
                c[2] = save;
            }
        }

        if(c[0] == 1){
            cout << 1 << endl;
        }else if(c[1] == 1){
            cout << 2 << endl;
        }else{
            cout << 3 << endl;
        }
    }
}
