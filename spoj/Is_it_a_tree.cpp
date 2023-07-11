#include <iostream>
#include <vector>

#define pb push_back 

using namespace std;
    
bool is_tree = true;

void dfs(int no, vector<int>& visit, vector<vector<int> >& adj){
    visit[no] = 1;
    int cont = 0;

    for(int i = 0; i != adj[no].size(); i++){
        if(visit[adj[no][i]] == 0){
            dfs(adj[no][i], visit, adj);
        }else{
            cont++;
            if(cont == 2){
                is_tree = false;
            }
        }
    }
}

int main(){
    int v, e;
    cin >> v >> e;

    vector<vector<int> > adj(v + 1);
    for(int i = 0; i != e; i++){
        int a, b;
        cin >> a >> b;

        adj[a].pb(b);
        adj[b].pb(a);
    }

    vector<int> visit(v + 1);
    dfs(1, visit, adj);

    for(int i = 1; i <= v; i++){
        if(visit[i] == 0){
            is_tree = false;
            break;
        }
    }

    if(is_tree){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
}
