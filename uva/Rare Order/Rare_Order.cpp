#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

void dp(map<pair<int, int>, bool> &adj, vector<pair<bool, int>> &v, string asw, int ind){
    if(ind == v.size()){
        cout << asw << endl;
        return;
    }

    for(auto &it : v){
        if(it.first){
            bool val = true;
            for(auto &jt : v){
                if(jt.first && adj[{it.second, jt.second}]){
                    val = false;
                    break;
                }
            }

            if(val){
                it.first=false;
                dp(adj, v, asw+(char)(it.second+'A'), ind+1);
                it.first=true;
            }
        }
    } 
}

int main(){
    string s, last = "";
    vector<bool> v(26);
    map<pair<int, int>, bool> adj;

    while(cin >> s){
        for(auto it : last){
            v[it-'A'] = true;
        }

        if(s == "#"){
            vector<pair<bool, int>> visit;
            for(int i = 0; i != v.size(); i++){
                if(v[i]){
                    visit.push_back({true, i});
                }
            }

            dp(adj, visit, "", 0);
            last = "";
            v = vector<bool>(26);
            adj.clear();

            continue;
        }

        if(last == ""){
            last = s;
            continue;
        }
        
        int mn = min(last.size(), s.size());
        for(int i = 0; i != mn; i++){
            if(last[i] == s[i]){
                continue;
            }

            adj[{s[i]-'A', last[i]-'A'}] = true;
            break;
        }
        last = s;
    }
}
