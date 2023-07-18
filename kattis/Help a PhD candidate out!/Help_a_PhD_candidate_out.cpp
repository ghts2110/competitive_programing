#include <iostream>
#include <string>

using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        string s;
        cin >> s;

        int n1 = 0, n2 = 0;
        bool v = true, c = false;
        for(int i = 0; i != s.size(); i++){
            if(s[i] == '+'){
                c = true;
                continue;
            }

            if(s[i] == '='){
                v = false;
                break;
            }

            if(c){
                n2 = n2*10 + (s[i] - '0');
            }else{
                n1 = n1*10 + (s[i] - '0');
            }
        }

        if(v){
            cout << n1 + n2 << endl;
        }else{
            cout << "skipped" << endl;
        }
    }
}
