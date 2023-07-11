#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int mx;

void dfs(int v, int dist[], vector<int> adj[]){
    for(int i = 0; i != adj[v].size(); i++){
        if(dist[adj[v][i]] != -1){
            continue;
        }

        dist[adj[v][i]] = dist[v] + 1;
        dfs(adj[v][i], dist, adj);
        mx = max(mx, dist[adj[v][i]]);
    }
}

int main(){
    int n, t = 0;
    
    while(1){
        cin >> n;
        
        if(n == 0){
            break;
        }

        vector<int> adj[101];
        int dist[101];
        
        for(int i = 0; i != n-1; i++){
            int a, b;
            cin >> a >> b;

            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        int mn_dist = 1e9;
        int value = 0;

        for(int i = 1; i <= n; i++){
            mx = -1;
            for(int j = 1; j <= n; j++){
                dist[j] = -1;
            }

            dist[i] = 0;
            dfs(i, dist, adj);
        
            if(mx < mn_dist){
                mn_dist = mx;
                value = i;
            }
        }

        cout << "Teste " << ++t << endl;
        cout << value << endl << endl;

        for(int i = 0; i != 101; i++){
            adj[i].clear();
        }
    }
}
