#include <iostream>
#include <string>

using namespace std;

int main(){
    int t;
    cin >> t;

    for(int test = 1; test <= t; test++){
        string s;
        cin >> s;

        int cont = s.size();
        for(int i = 0; i != s.size(); i++){
            if(s[i] == 'D') {
                cont--;
            }else if(s[i] == 'B'){
                cont--;
                for(int j = i-1; j >= i-2 && j != -1; j--){
                    if(s[j] == '-'){
                        s[j] = '*';
                        cont--;
                    }
                }
            }else if(s[i] == 'S') {
                cont--;
                if (i + 1 < s.size() && s[i + 1] == '-') {
                    s[i+1] = '*';
                    cont--;
                }
                if (i - 1 > -1 && s[i - 1] == '-') {
                    s[i-1] = '*';
                    cont--;
                }
            }
        }

        cout << "Case "<<test<<": ";
        cout << cont << endl;
    }

}