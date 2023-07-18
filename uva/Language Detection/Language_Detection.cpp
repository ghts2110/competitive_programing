#include <iostream>
#include <string>

using namespace std;

int main(){
    string s;
    int t = 1;
    while(1){
        cin >> s;
        if(s == "#"){
            break;
        }

        cout << "Case " << t << ": ";
        t++;
        if(s == "HELLO"){
            cout << "ENGLISH" << endl;
        }else if(s == "HOLA"){
            cout << "SPANISH" << endl;
        }else if(s == "HALLO"){
            cout << "GERMAN" << endl;
        }else if(s == "BONJOUR"){
            cout << "FRENCH" << endl;
        }else if(s == "CIAO"){
            cout << "ITALIAN" << endl;
        }else if(s == "ZDRAVSTVUJTE"){
            cout << "RUSSIAN" << endl;
        }else{
            cout << "UNKNOWN" << endl;
        }
    }

}
