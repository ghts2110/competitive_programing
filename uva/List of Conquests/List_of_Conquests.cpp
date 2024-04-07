#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(){
    int t;
    cin >> t;
    map<string, int> mp;
    
    string s;
    getline(cin, s);
    while(t--){
        getline(cin, s);
        string s1 = "";
        for(auto it : s){
            if(it == ' ' && s1 != ""){
                break;
            }
            if(it == ' '){
                continue;
            }

            s1+=it;
        }
        mp[s1]++;
    }

    for(auto it : mp){
        cout << it.first << " " << it.second << endl;
    }
}
