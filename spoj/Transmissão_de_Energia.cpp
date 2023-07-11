#include <iostream>
#include <vector>

#define pb push_back

using namespace std;

void dfs(int no, vector<int>& visit, vector<vector<int> >& adj){
    visit[no] = 1;

    for(int i = 0; i != adj[no].size(); i++){
        if(visit[adj[no][i]] == 0){
            dfs(adj[no][i], visit, adj);
        }
    }

}

int main(){
    int e, l, cont = 1;

    while(1){
        cin >> e >> l;
        if(e == 0 && l == 0){
            break;
        }

        vector<vector<int> > adj(e+1);
        for(int i = 0; i != l; i++){
            int a, b;
            cin >> a >> b;

            adj[a].pb(b);
            adj[b].pb(a);
        }

        vector<int> visit(e+1);
        dfs(1, visit, adj);


        bool ans = true;
        for(int i = 1; i <= e; i++){
            if(visit[i] == 0){
                ans = false;
                break;
            }
        }
    
        cout << "Teste " << cont << endl;
        cont++;

        if(ans){
            cout << "normal" << endl;
        }else{
            cout << "falha" << endl;
        }

        cout << endl;
    }
}
