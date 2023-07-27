#include <iostream>
#include <string>

using namespace std;

int main(){
    int t;
    while(cin >> t){
        if(t==0){
            break;
        }

        string asw;
        int mx = -1;
        for(int i = 0; i != t; i++){
            int cont = 0;
            string s;
            cin >> s;

            for(int i = 1; i != s.size(); i++){
                if(s[i] == s[i-1] && (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'y')){
                    cont++;
                }
            }

            if(mx < cont){
                asw = s;
                mx = cont;
            }
        }

        cout << asw << endl;
    }
}
