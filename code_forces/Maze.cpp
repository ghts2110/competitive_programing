#include <iostream>
#include <vector>
#include <string>
#include <map>

#define pb push_back

using namespace std;
    
vector<string> mat;
vector<int> visit(250001);
map<int, pair<int, int> > mp;
int k;

void dfs(int no, vector<vector<int> >& adj){
    
    visit[no] = 1;
    for(int i = 0; i != adj[no].size(); i++){
        if(visit[adj[no][i]] == 0){
            dfs(adj[no][i], adj);
        }
    }

    if(k != 0){
        k--;
        mat[mp[no].first][mp[no].second] = 'X';
    }
}

int main(){
    int n, m;
    cin >> n >> m >> k;    
    
    for(int i = 0; i != n; i++){
        string s;
        cin >> s;
        
        mat.pb(s);
    }

    int cont = 0;
    vector<vector<int> > adj(n*m+1);

    int start = 0;
    for(int i = 0; i != n; i++){
        for(int j = 0; j != m; j++){
            cont++;
            if(mat[i][j] == '#'){
                continue;
            }
            start = cont;
            mp[cont].first = i;
            mp[cont].second = j;

            if(i - 1 >= 0 && mat[i-1][j] == '.'){
                adj[cont].pb(cont - m);
            }

            if(i + 1 < n && mat[i+1][j] == '.'){
                adj[cont].pb(cont + m);
            }

            if(j - 1 >= 0 && mat[i][j - 1] == '.'){
                adj[cont].pb(cont-1);
            }

            if(j + 1 < m && mat[i][j+1] == '.'){
                adj[cont].pb(cont+1);
            }
        }
    }

    dfs(start, adj);
    for(int i = 0; i != n; i++){
        cout << mat[i] << endl;
    }
}
