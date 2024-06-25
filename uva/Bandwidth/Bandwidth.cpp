#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    string s;
    while(cin >>s){
        if(s == "#"){
            break;
        }
        char no = ' ';
        char c;

        vector<vector<int>> adj(26);
        vector<char> v;
        vector<bool> visit(26, true);

        for(auto it : s){
            if(it == ':'){
                no = c;
                continue;
            }

            if(it == ';'){
                no = ' ';
                continue;
            }

            c = it;
            if(visit[c-'A']){
                visit[c-'A'] = false;
                v.push_back(c);
            }

            if(no != ' '){
                adj[no-'A'].push_back(it-'A');
            }
        }
        adj[no-'A'].push_back(c-'A');
        if(visit[c-'A']){
            v.push_back(c);
        }
            
        s = "";
        for(auto it : v){
            s += it;
        }

        sort(s.begin(), s.end());
        
        pair<int, string> asw = {1e9, ""};
        do{
            vector<int> save(26);
            for(int i = 0; i != s.size(); i++){
                save[s[i]-'A'] = i;
            }

            int mx = 0;
            for(int i = 0; i != adj.size(); i++){
                for(auto it : adj[i]){
                    mx = max(mx, abs(save[i]- save[it]));
                }
            }
            if(mx < asw.first){
                asw.first = mx;
                asw.second = s;
            }
        }while(next_permutation(s.begin(), s.end()));
    
        for(auto it : asw.second){
            cout << it << ' ';
        }
        cout << "-> " << asw.first << endl;
    }
}
