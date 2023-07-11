#include <iostream>
#include <vector>
#include <cmath>

#define pb push_back
#define ll long long

using namespace std;

void dfs(int no, vector<int>& visit, vector<vector<int> >& adj, vector<int>& sz, vector<ll>& values){
    visit[no] = 1;
    sz[no] = 1;

    for(int i = 0; i != adj[no].size(); i++){
        if(visit[adj[no][i]] == 0){
            dfs(adj[no][i], visit, adj, sz, values);
            sz[no] += sz[adj[no][i]];
        }
    }
    
    values[1] += sz[no]; 
    visit[no] = 0;
}

void dfs2(int no, vector<int>& visit, vector<vector<int> >& adj, vector<int>& sz, vector<ll>& values, int pre){
    visit[no] = 1;
    values[no] = values[pre] - sz[no] + sz[1] - sz[no];

    for(int i = 0; i != adj[no].size(); i++){
        if(visit[adj[no][i]] == 0){
            dfs2(adj[no][i], visit, adj, sz, values, no);
        }
    }
} 

int main(){
    int n;
    cin >> n;

    vector<vector<int> > adj(n+1);

    for(int i = 0; i != n-1; i++){
        int a, b;
        cin >> a >> b;
    
        adj[a].pb(b);
        adj[b].pb(a);
    }
    
    vector<int> visit(n+1), sz(n+1);
    vector<ll> values(n+1);

    dfs(1, visit, adj, sz, values);
    visit[1] = 1;
    for(int i = 0; i != adj[1].size(); i++){
        dfs2(adj[1][i], visit, adj, sz, values, 1);
    }

    long long mx = 0;
    for(int i = 1; i <= n; i++){
        mx = max(mx, values[i]);
    }

    cout << mx << endl;
}
