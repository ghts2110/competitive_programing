#include <iostream>
#include <vector>

#define pb push_back

using namespace std;

bool cycle = true;

void dfs(int no, vector<int>& visit, vector<vector<int> >& adj){
    if(adj[no].size() != 2){
        cycle = false;
    }

    visit[no] = 1;
    for(int i = 0; i != adj[no].size(); i++){
        if(visit[adj[no][i]] == 0){
            dfs(adj[no][i], visit, adj);
        }
    }
}

int main(){
    int n, m;
    cin >> n >> m;

    vector<vector<int> > adj(n+1);
    for(int i = 0; i != m; i++){
        int a, b;
        cin >> a >> b;

        adj[a].pb(b);
        adj[b].pb(a);
    }

    vector<int> visit(n + 1);
    int cont = 0;
    for(int i = 1; i <= n; i++){
        cycle = true;
        if(visit[i] == 0){
            dfs(i, visit, adj);
            if(cycle){
                cont++;
            }
        }
    }

    cout << cont << endl;
}
