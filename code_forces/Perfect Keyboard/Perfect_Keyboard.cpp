#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>

using namespace std;

bool possib = true;
string new_string;
map<int, char> mp;

void map_letter(){
    mp[0] = 'a';
    mp[1] = 'b';
    mp[2] = 'c';
    mp[3] = 'd';
    mp[4] = 'e';
    mp[5] = 'f';
    mp[6] = 'g';
    mp[7] = 'h';
    mp[8] = 'i';
    mp[9] = 'j';
    mp[10] = 'k';
    mp[11] = 'l';
    mp[12] = 'm';
    mp[13] = 'n';
    mp[14] = 'o';
    mp[15] = 'p';
    mp[16] = 'q';
    mp[17] = 'r';
    mp[18] = 's';
    mp[19] = 't';
    mp[20] = 'u';
    mp[21] = 'v';
    mp[22] = 'w';
    mp[23] = 'x';
    mp[24] = 'y';
    mp[25] = 'z';
}

void dfs_string(int k, vector<int>& visit, vector<set<int> >& adj){
    visit[k] = 1;

    cout << mp[k];
    for(set<int>::iterator it = adj[k].begin(); it != adj[k].end(); it++){
        if(visit[*it] == 0){
            dfs_string(*it, visit, adj);
        }
    }
}

void dfs(int k, int start, vector<int>& visit, vector<set<int> >& adj, int cont){
    
    visit[k] = 1;

    for(set<int>::iterator it = adj[k].begin(); it != adj[k].end(); it++){
        
        if(*it == start){
            cont++;
            if(cont == 2){
                possib = false;
            }

            continue;
        }

        if(visit[*it] == 0){
            dfs(*it, start, visit, adj, cont);
        }
    }
}

int main(){
    int t;
    cin >> t;
    map_letter();

    while(t--){
        string s;
        vector<set<int> > adj(26);
        cin >> s;
    
        for(int i = 0; i != s.size(); i++){
            if(i + 1 != s.size() && s[i] == s[i+1]){
                continue;
            }
            
            if(i + 1 != s.size()){
                adj[s[i] - 97].insert(s[i+1] - 97);
                adj[s[i+1] - 97].insert(s[i] - 97);
            }
        }

        int start = 0;
        possib = true;
        for(int i = 0; i != 26; i++){
            if(adj[i].size() == 1){
                start = i;
                continue;
            }

            if(adj[i].size() > 2){
                possib = false;
                break;
            }
        }
        
        for(int i = 0; i != 26; i++){
            vector<int> visit(26);
            dfs(i, i, visit, adj, 0);
        }

        if(possib){
            cout << "YES" << endl;
            new_string = "";
        
            vector<int> visit(26);
            dfs_string(start, visit, adj);
           
            for(int i = 0; i != 26; i++){
                if(visit[i] == 0){
                    cout << mp[i];
                }
            }
            cout << endl;
        }else{
            cout << "NO" << endl; 
        }
    }
}
