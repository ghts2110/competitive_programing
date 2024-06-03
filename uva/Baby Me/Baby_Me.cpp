#include <iostream>
#include <string> 

using namespace std;

int main(){
    int t;
    cin >> t;
    
    string s;
    getline(cin, s);
    int test = 1;
    while(t--){
        cout << "Case "<<test<<": ";
        test++;

        getline(cin, s);

        string save = "";
        double asw = 0;
        for(int i = 0; i != s.size(); i++){
            if(isdigit(s[i])){
                save += s[i];
            }

            if(!isdigit(s[i]) || i == s.size()-1){
                string c = "";
                c += s[i];
                if(c == "\x96"){
                    asw += stoi(save)*0.5;
                    save = "";
                }else if(c == "\xe4"){
                    asw += stoi(save)*0.05;
                    save = "";
                }
            }
        }

        cout << asw << endl;
    }
}
