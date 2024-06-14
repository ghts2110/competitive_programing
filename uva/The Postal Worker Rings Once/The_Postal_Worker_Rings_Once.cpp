#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

void djk(vector<vector<pair<int, int>>> &adj, vector<int> &visit, int start){
    set<pair<int, int>> st;
    st.insert({0, start});
    visit[start] = 0;

    while(!st.empty()){
        int no  = (*st.begin()).second;
        int cost = (*st.begin()).first;
        st.erase(st.begin());

        for(auto it : adj[no]){
            if(visit[it.first] > cost + it.second){
                visit[it.first] = cost + it.second;
                st.insert({visit[it.first], it.first});
            } 
        }
    }
}

int main(){
    string s;
    vector<vector<pair<int, int>>> adj(26, vector<pair<int, int>>());
    vector<bool> even(26, true);
    int sum = 0;

    while(cin >> s){
        if(s == "deadend"){
            bool val = true;
            int a = -1, b;
            for(int i = 0; i != 26; i++){
                val &= even[i];
                if(!even[i]){
                    if(a == -1){
                        a = i;
                    }else{
                        b = i;
                    }
                }
            }
            
            if(val){
                cout << sum << endl;
            }else{
                vector<int> visit(26, 1e9);
                djk(adj, visit, a);
                cout << visit[b]+sum << endl;
            }

            sum = 0;
            even = vector<bool> (26, true);
            adj = vector<vector<pair<int, int>>>(26, vector<pair<int, int>>());
            continue;
        }

        sum += s.size();
        
        even[s[0]-'a'] = !even[s[0]-'a'];
        even[s[s.size()-1]-'a'] = !even[s[s.size()-1]-'a'];

        adj[s[0]-'a'].push_back({s[s.size()-1]-'a', s.size()});
        adj[s[s.size()-1]-'a'].push_back({s[0]-'a', s.size()});
    }
}
