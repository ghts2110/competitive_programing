#include <iostream>
#include <vector>
#include <string>
#include <set>


using namespace std;

void djk(int no, vector<vector<pair<int, int>>> &adj, vector<int> &dist){
    set<pair<int, int>> st;
    st.insert({no, 0});
    dist[no] = 0;

    while(!st.empty()){
        int n = (*st.begin()).first;
        int c = (*st.begin()).second;
        st.erase(st.begin());

        for(auto it : adj[n]){
            if(it.second + c < dist[it.first] || dist[it.first] == -1){
                st.insert({it.first, it.second+c});
                dist[it.first] = it.second+c;
            }
        }

    }
}
int main(){
    string s;
    while(getline(cin, s)){
        vector<vector<pair<int, int>>> adj(10001);
        int f = true;
        while(f || getline(cin, s)){
            f = false;
            if(s == ""){
                break;
            }
            int a = -1, b = -1, c = -1;
            string save = "";
            for(int i = 0; i != s.size(); i++){
                if(s[i] != ' '){
                    save+=s[i];
                }
                if(s[i] == ' ' || i == s.size()-1){
                    if(a == -1){
                        a = stoi(save);
                    }else if(b == -1){
                        b = stoi(save);
                    }else{
                        c = stoi(save);
                    }
                    save = "";
                }
            }
            adj[a].push_back({b,c});
            adj[b].push_back({a,c});
        }

        vector<int> dist(10001, -1);
        djk(1, adj, dist);

        pair<int, int> m = {-1, -1};
        for(int i = 1; i != dist.size(); i++){
            if(dist[i] > m.first){
                m.first = dist[i];
                m.second = i;
            }
        }

        dist = vector<int> (10001, -1);
        djk(m.second, adj, dist);
        for(int i = 1; i != dist.size(); i++){
            if(dist[i] > m.first){
                m.first = dist[i];
                m.second = i;
            }
        }

        cout << m.first << endl;
    }
}
