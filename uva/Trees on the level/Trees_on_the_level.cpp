#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;
vector<vector<int>> asw(256);
int sz = 0;

void dfs(string no, map<string, vector<string>> &adj, int deep, map<string, int> &mp){
    sz++;
    asw[deep].push_back(mp[no]);
    
    if(adj[no].size() == 2 && adj[no][0] > adj[no][1]){
        swap(adj[no][0], adj[no][1]);
    }
    if(adj[no].size() > 2){
        return;
    }
    if(adj[no].size() == 2 && adj[no][0] == adj[no][1]){
        return;
    }

    for(auto it : adj[no]){
        dfs(it, adj, deep+1, mp);
    }
}

int main(){
    string s;
    map<string, vector<string>> adj;
    map<string, int> mp;
    bool val = true;
    int cont = 0;

    while(cin >> s){
        if(s == "()"){
            dfs("", adj, 0, mp);
        
            if(sz == cont && val){
                for(int i = 0; i != 256; i++){
                    for(auto it : asw[i]){
                        if(i != 0){
                            cout << " ";
                        }

                        cout << it;
                    }
                }
                cout << endl;
            }else{
                cout << "not complete" << endl;
            }

            val = true;
            asw = vector<vector<int>>(256);
            sz = 0;
            mp.clear();
            adj.clear();
            cont = 0;
            continue;
        }

        cont++;
        string num = "";
        string position = "";
        for(int i = 1; i != s.size()-1; i++){
            if(isdigit(s[i])){
                num += s[i];
                continue;
            }

            if(s[i] == ','){
                continue;
            }

            position += s[i];
        }
        
        mp[position] = stoi(num);

        if(position == ""){
            continue;
        }else{
            string save = position;
            save.erase(save.end()-1);
            adj[save].push_back(position);
        }
    

        
    }

}
