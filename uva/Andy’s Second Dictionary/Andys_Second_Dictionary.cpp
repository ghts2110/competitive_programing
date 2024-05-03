#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(){
    string s;
    string save = "";
    bool f = false;
    
    map<string, int> mp;
    while(cin >> s){
        for(int i = 0; i != s.size(); i++){
            if(i == s.size()-1 && s[i] == '-'){
                f = true;
                continue;
            }
            if(!isalpha(s[i]) && s[i] != '-'){
                if(save == ""){
                    continue;
                }
                mp[save]++;
                save="";
                continue;
            }

            save += tolower(s[i]);
        }
        if(f){
            f = false;
            continue;
        }
        
        if(save == ""){
            continue;
        }
        mp[save]++;
        save ="";
    }

    for(auto it : mp){
        cout << it.first << endl;
    }
}
