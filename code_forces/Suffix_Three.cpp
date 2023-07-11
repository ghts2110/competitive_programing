#include <iostream>
#include <string>

using namespace std;

int main(){
    int t;
    cin >> t;

    string s;

    while(t--){
        cin >> s;
        if(s[s.size()-1] == 'o'){
            cout << "FILIPINO" << endl;
        }else if(s[s.size() -1] == 'u'){
            cout << "JAPANESE" << endl;
        }else{
            cout << "KOREAN" << endl;
        }
    }
}
