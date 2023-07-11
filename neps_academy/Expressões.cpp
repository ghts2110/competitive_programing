#include <iostream>
#include <deque>
#include <string>

using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        string s;
        cin >> s;

        deque<char> p;
        int validate = 1;
        for(int i = 0; i != s.size(); i++){
            if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
                p.push_back(s[i]);
            }else{
                if(p.size() == 0 || (p.back() == '(' && s[i] != ')') || (p.back() == '[' && s[i] != ']') || (p.back() == '{' && s[i] != '}')){
                    validate = 0;
                    break;
                }

                p.pop_back();
            }
        }

        if(validate == 1){
            cout << 'S' << endl;
        }else{
            cout << 'N' << endl;
        }
    }
}
