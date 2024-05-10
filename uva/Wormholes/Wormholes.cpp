#include <iostream>
#include <vector>
#include <set>

using namespace std;

bool djk(int start, vector<vector<pair<int, int>>> &adj, vector<int> &dist){
    set<pair<int, int>> st;
    st.insert({start, 0});
    dist[start] = 0;

    while(!st.empty()){
        int no = (*st.begin()).second;
        int cost = (*st.begin()).first;
        if(cost < 0){
            return true;
        }
        st.erase(st.begin());

        for(auto it : adj[no]){
            if(cost + it.second < dist[it.first]){
                dist[it.first] =  cost + it.second;
                st.insert({dist[it.first], it.first});
            }
        }
    }

    return false;
}

int main(){
    int t;
    cin >> t;

    while(t--){
        int n, m;
        cin >> n >> m;

        vector<vector<pair<int,int>>> adj(n);
        for(int i = 0; i != m; i++){
            int a, b, c;
            cin >> a >> b >> c;
            adj[a].push_back({b, c});
        }

        vector<int> dist(n, 1e9);
        if(djk(0, adj, dist)){
            cout << "possible" << endl;
        }else{
            cout << "not possible" << endl;
        } 
    }
}
