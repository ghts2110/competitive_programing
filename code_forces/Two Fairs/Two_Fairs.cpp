#include <iostream>
#include <vector>

#define pb push_back

using namespace std;

int cont, f1, f2;
bool isMid;

void dfs(int no, vector<int>& visit, vector<vector<int> >& adj){
    if(no == f2){
        isMid = true;
        return ;
    }    
    
    cont ++;
    visit[no] = 1;
    for(int i = 0; i != adj[no].size(); i++){
        if(visit[adj[no][i]] == 0){
            dfs(adj[no][i], visit, adj);
        }
    }
}

int main(){
    int t;
    cin >> t;

    while(t--){
        long long n, m, a, b;
        cin >> n >> m >> f1 >> f2;

        vector<int> visit(n+1);
        visit[f1] = 1;
        
        vector<vector<int> > adj(n+1);
        for(int i = 0; i != m; i++){
            cin >> a >> b;
        
            adj[a].pb(b);
            adj[b].pb(a);
        }

        n -= 2;
        long long contA = 0;
        for(int i = 0; i != adj[f1].size(); i++){
            cont = 0;
            isMid = false;
                
            if(visit[adj[f1][i]] == 0 && adj[f1][i] != f2) {
                dfs(adj[f1][i], visit, adj);
            }
            
            if(isMid){
                n -= cont;
            }else{
                contA += cont;
            }
        }
        
        cout << contA * (n - contA) << endl;
    }
}
