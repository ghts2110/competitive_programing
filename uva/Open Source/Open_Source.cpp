#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>    

using namespace std;

bool my(pair<int, string> p1, pair<int, string> p2){
    if(p1.first > p2.first){
        return true;
    }else if(p1.first < p2.first){
        return false;
    }

    return p1.second < p2.second;
}

int main(){
    string s;
    vector<pair<int, string>> names;
    map<string, int> mp;

    while(getline(cin, s)){
        if(s == "0"){
            break;
        }

        if(s == "1"){
            sort(names.begin(), names.end(), my);
            for(auto it : names){
                cout << it.second << " " << it.first << endl;
            }
            
            names.clear();
            mp.clear();
            continue;
        }

        if(s[0] >= 'A' && s[0] <= 'Z'){
            names.push_back({0, s});
        }else{
            if(mp[s] == -1 || mp[s] == names.size()){
                continue;
            }else if(mp[s] != 0){
                names[mp[s]-1].first--;
                mp[s] = -1;
            }else{
                mp[s] = names.size();
                names[mp[s]-1].first++;
            }
        }
    }
}
