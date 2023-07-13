#include <iostream>
#include <vector>
#define pb push_back

using namespace std;

vector<vector<int> > adj(1001);
vector<int> vist(1001);

void dfs(int no){
    vist[no] = 1;

    for(int i = 0; i != adj[no].size(); i++){
        if(vist[adj[no][i]] == 0){
            vist[adj[no][i]] = 1;
            dfs(adj[no][i]);
        }
    }
}

int main(){
    int n, m;
    cin >> n >> m;

    for(int i = 0; i != m; i++){
        int a, b;
        cin >> a >> b;

        adj[a].pb(b);
        adj[b].pb(a);
    }
    
    int cont = 0;
    for(int i = 1; i <= n; i++){
        if(vist[i] == 0){
            cont++;
            dfs(i);
        }
    }

    cout << cont << endl;
}
