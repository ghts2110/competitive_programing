#include <iostream>
#include <vector>

using namespace std;
bool asw;

void dfs(int no, vector<vector<int>> &adj, vector<int> &visit, int last){
    if(last == 0){
        visit[no] = 1;
    }else{
        visit[no] = 0;
    }
 
    for(auto it : adj[no]){
        if(visit[it] == visit[no]){
            asw = false;
            return;
        }
    }

    for(auto it : adj[no]){
        if(visit[it] == -1){
            dfs(it, adj, visit, visit[no]);
        }
    }
}

int main(){
    int n;
    while(cin >> n){
        if(n == 0){
            break;
        }

        int m;
        cin >> m;
    
        vector<vector<int>> adj(n);
        for(int i = 0; i != m; i++){
           int a, b;
           cin >> a >> b;

           adj[a].push_back(b);
           adj[b].push_back(a);
        }

        asw = true;
        vector<int> visit(n,-1);
        dfs(0, adj, visit, -1);
        
        if(asw){
            cout << "BICOLORABLE." << endl;
        }else{
            cout << "NOT BICOLORABLE." << endl;
        }
    }
}
