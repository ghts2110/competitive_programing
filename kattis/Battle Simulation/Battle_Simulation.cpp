#include <iostream>
#include <string>

using namespace std;

int main(){
    string s;
    while(cin >> s){
        s += s[s.size() -1];
        for(int i = 1; i != s.size(); i++){
            if(i + 1 < s.size() && s[i] != s[i-1] && s[i] != s[i+1] && s[i-1] != s[i+1]){
                cout << "C";
                i+=2;
            }else if(s[i-1] == 'R'){
                cout << "S";
            }else if(s[i-1] == 'B'){
                cout << "K";
            }else{
                cout << "H";
            }
        }

        cout << endl;
    }
}
