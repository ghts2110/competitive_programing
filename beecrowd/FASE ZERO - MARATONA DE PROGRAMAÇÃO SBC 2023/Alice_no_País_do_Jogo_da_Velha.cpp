#include <iostream>
#include <string>

using namespace std;

int main(){
    string s;
    cin >> s;
    
    int contO = 0;
    for(int i = 0; i != 3; i++){
        if(s[i] == 'O'){
            contO++;
        }
    }

    if(contO != 1){
        cout << "?" << endl;
        return 0;
    }

    for(int i = 1; i != 3; i++){
        if(s[i] == s[i-1]){
            if(s[i] == 'O'){
                cout << "Bob" << endl;
            }else{
                cout << "Alice" << endl;
            }
            return 0;
        }
    }

    cout << "*" << endl;
}
