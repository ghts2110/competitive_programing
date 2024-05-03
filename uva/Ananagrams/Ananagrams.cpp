#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    string s;
    map<vector<char>, string> mp;
    while(cin >> s){ 
        if(s == "#"){
            break;               
        }
        vector<char> v(26);
        for(int i = 0; i != s.size(); i++){
            v[tolower(s[i])-'a']++;
        }

        if(mp[v] == ""){
            mp[v] = s;
        }else{
            mp[v] = "-";
        }
    }

    vector<string> save;
    for(auto it : mp){
        if(it.second != "-"){
            save.push_back(it.second);
        }
    }

    sort(save.begin(), save.end());
    for(auto it : save){
        cout << it << endl;
    }
}
