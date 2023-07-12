#include <iostream>
#include <vector>

#define pb push_back

using namespace std;

int mx = 0;
int sheet;

void dfs(int no, int cont, vector<int>& visit, vector<int> adj[]){
    
    if(adj[no].size() == 1 && cont > mx){
        mx = cont;
        sheet = no;
    }

    visit[no] = 1;
    for(int i = 0; i != adj[no].size(); i++){
        if(visit[adj[no][i]] == 0){
            dfs(adj[no][i], cont+1, visit, adj);
        }
    }

    visit[no] = 0;
}

int main(){
    int n;
    cin >> n;

    vector<int> adj[n+1];
    for(int i = 0; i != n-1; i++){
        int a, b;
        cin >> a >> b;

        adj[a].pb(b);
        adj[b].pb(a);
    }
 
    vector<int> visit(n+1);
    dfs(1, 0, visit, adj);

    mx = 0;
    dfs(sheet, 0, visit, adj);

    cout << mx<< endl;
}
