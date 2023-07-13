#include <iostream>
#include <vector>
#include <string>
#include <cmath>

#define pb push_back

using namespace std;

int dfs(int no, int cont, vector<int>& visit, vector<vector<int> >& adj){
    visit[no] = 1;

    for(int i = 0; i != adj[no].size(); i++){
        if(visit[adj[no][i]] == 0){
            cont += dfs(adj[no][i], 1, visit, adj);
        }
    }

    return cont;
}
int main(){
    int n, m;
    while(cin >> n >> m){
        vector<string> mp;

        for(int i = 0; i != n; i++){
            string s;
            cin >> s;

            mp.pb(s);    
        }

        int x, y;
        cin >> x >> y;

        vector<int> visit(n * m);
        vector<vector<int> > adj(n * m);
        int cont = 0;
        for(int i = 0; i != n; i++){
            for(int j = 0; j != m; j++){
                if(mp[i][j] == mp[x][y]){
                    if(i+1 != n && mp[i][j] == mp[i+1][j]){
                        adj[cont].pb(cont+m);
                        adj[cont+m].pb(cont);
                    }

                    if(j+1 != m && mp[i][j] == mp[i][j+1]){
                        adj[cont].pb(cont+1);
                        adj[cont+1].pb(cont);
                    }else if(j+1 == m && mp[i][j] == mp[i][0]){
                        adj[cont].pb(i*m);
                        adj[i*m].pb(cont);
                    }
                }else{
                    visit[cont] = 1;
                }
                cont++;
            }
        }

        cont = y + (x*m);
        dfs(cont, 1, visit, adj);

        int mx = 0;
        for(int i = 0; i != n * m; i++){
            if(visit[i] == 0){
                mx = max(mx, dfs(i, 1, visit, adj));
            }
        }
        cout << mx << endl;
    }
}
