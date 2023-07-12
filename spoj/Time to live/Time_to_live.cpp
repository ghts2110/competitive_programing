#include <iostream>
#include <vector>
#include <deque>

#define pb push_back

using namespace std;

int value;

int mx;
int sheet;

void dfs(int no, int cont, vector<int>& visit, vector<vector<int> >& adj){

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
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        vector<vector<int> > adj(n);
        for(int i = 0; i != n -1; i++){
            int a, b;
            cin >> a >> b;

            adj[a].pb(b);
            adj[b].pb(a);
        }


        vector<int> visit(n);
        
        mx = 0;
        dfs(0, 0, visit, adj);

        mx = 0;
        dfs(sheet, 0, visit, adj);

        if(mx % 2 == 1){
            mx = mx/2;
            mx++;
        }else{
            mx = mx/2;
        }
        cout << mx<< endl;
    }
}
