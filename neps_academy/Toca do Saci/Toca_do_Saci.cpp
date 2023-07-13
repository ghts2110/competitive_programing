#include <iostream>
#include <vector>

#define pb push_back
using namespace std;
    
vector<vector<int> > adj(1000001);
vector<int> visit(1000001);

int dfs(int start, int end, int cont){
    visit[start] = 1;
    if(start == end){
        return cont;
    }else if(adj[start].size() == 0){
        return 0;
    }
    
    int best = 1;
    for(int i = 0; i != adj[start].size(); i++){
        if(visit[adj[start][i]] == 0){
            best = max(cont, dfs(adj[start][i], end, cont + 1));
        }
    }

    return best;
}

int main(){
    int n, m;
    cin >> n >> m;

    vector<vector<int> > mat(n, vector<int> (m));
    
    for(int i = 0; i != n; i++){
        for(int j = 0; j != m; j++){
            int num; 
            cin >> num;

            mat[i][j] = num;
        }
    }

    int cont = 0;

    int start, end;
    for(int i = 0; i != n; i++){
        for(int j = 0; j != m; j++){
            cont++;
            if(mat[i][j] == 0){
                continue;
            }else if(mat[i][j] == 2){
                start = cont;
            }else if(mat[i][j] == 3){
                end = cont;
            }
            
            
            if(i - 1 >= 0 && mat[i-1][j] != 0){
                adj[cont].pb(cont - m);
            }

            if(i + 1 < n && mat[i+1][j] != 0){
                adj[cont].pb(cont + m);
            }

            if(j - 1 >= 0 && mat[i][j-1] != 0){
                adj[cont].pb(cont - 1);
            }

            if(j + 1 < m && mat[i][j+1] != 0){
                adj[cont].pb(cont + 1);
            }
        }
    }

    cont = dfs(end, start, 1);
    cout << cont << endl;
}
