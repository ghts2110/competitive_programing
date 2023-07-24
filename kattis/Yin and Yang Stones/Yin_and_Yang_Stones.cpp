#include <iostream>
#include <string>

using namespace std;

int main(){
    string s;
    while(cin >> s){
        int w = 0 , b = 0 ;
        for(int i = 0; i != s.size(); i++){
            if(s[i] == 'W'){
                w++;
            }else{
                b++;
            }
        }

        if(w == b){
            cout << 1 << endl;
        }else{
            cout << 0 << endl;
        }
    }
}
