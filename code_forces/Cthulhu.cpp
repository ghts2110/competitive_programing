#include <iostream>
#include <vector>

#define pb push_back

using namespace std;

int cont = 1;
vector<int> visit(101);

void dfs(int k, vector<vector<int> >& adj){
   
    visit[k] = 1;

    for(int i = 0; i != adj[k].size(); i++){
        if(visit[adj[k][i]] == 0){
            cont++;
            dfs(adj[k][i], adj);
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

    dfs(1, adj);

    if(n == m && n == cont){
        cout << "FHTAGN!" << endl;
    }else{
        cout << "NO" << endl;
    }
}
