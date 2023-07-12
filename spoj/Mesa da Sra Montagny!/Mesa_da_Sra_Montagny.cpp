#include <iostream>
#include <vector>

#define pb push_back

using namespace std;

bool ans;

void dfs(int no, int cont, int pre, vector<int>& visit, vector<vector<int> >& adj, vector<int>& num){
    visit[no] = 1;

    num[no] = cont;
    for(int i = 0; i != adj[no].size(); i++){
        if(visit[adj[no][i]] == 0 && adj[no][i] != pre){
            dfs(adj[no][i], cont+1, no, visit, adj, num);
        }else if(adj[no][i] != pre && (num[no] - num[adj[no][i]] + 1) % 2 == 1){
            ans = false;
        }
    }   

}

int main(){
    int n, m, t = 1;
    while(scanf("%d %d", &n, &m) == 2){
        ans = true;

        vector<vector<int> > adj(n+1);
        for(int i = 0; i != m; i++){
            int a, b;
            scanf("%d %d", &a, &b);
            adj[a].pb(b);
            adj[b].pb(a);
        }
        
        vector<int> visit(n+1), num(n + 1);
        for(int i = 1; i <= n; i++){
            if(visit[i] == 0){
                dfs(i, 0, 0, visit, adj, num);    
            }
        }
    
        cout << "Instancia " << t << endl;
        t++;
        if(ans){
            printf("sim\n");
        }else{
            printf("nao\n");
        }

        printf("\n");
    }
}
