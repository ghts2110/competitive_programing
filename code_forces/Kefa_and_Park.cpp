#include <iostream>
#include <vector>

#define pb push_back

using namespace std;

int cont = 0, m;

void dfs(int no, int cat, vector<int>& visit, vector<vector<int> >& adj){
    
    if(visit[no] == 1){
        cat--;
        if(cat == -1){
            return ;
        }
    }else{
        cat = m;
    
    }
    
    visit[no] = 2;
    bool sheet = true;
    for(int i = 0; i != adj[no].size(); i++){
        if(visit[adj[no][i]] != 2){
            sheet = false;
            dfs(adj[no][i], cat, visit, adj);
        }
    }

    if(sheet){
        cont++;
    }
}

int main(){
    int n;
    cin >> n >> m;

    vector<int> visit(1);
    for(int i = 0; i != n; i++){
        int num;
        cin >> num;

        visit.pb(num); 
    }

    vector<vector<int> > adj(n+1);
    for(int i = 0; i != n -1; i++){
        int a, b;
        cin >> a >> b;

        adj[a].pb(b);
        adj[b].pb(a);
    }
    
    cont = 0;
    dfs(1, m, visit, adj);
    cout << cont << endl;
}
