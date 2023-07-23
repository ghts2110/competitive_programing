#include <iostream>
#include <string>

using namespace std;

int main(){
    string s;
    cin >> s;

    bool validate = true;
    for(int i= 1; i != s.size(); i++){
        if(s[i] == 's' && s[i] == s[i-1]){
            validate = false;
        }
    }

    if(validate){
        cout << "no hiss" << endl;
    }else{
        cout << "hiss" << endl;
    }
}
