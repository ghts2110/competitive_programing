#include <iostream>
#include <vector>
#include <stack>

using namespace std;
int n, m;
pair<int, vector<int>> save;

void dp(int ind, vector<vector<int>> &adj, vector<int> asw, vector<int> visit){
    if(ind > n){
        if(save.first < asw.size()){
            save.first = asw.size();
            save.second = asw;
        }
        return;
    }
    dp(ind+1, adj, asw, visit);

    if(asw.size() == 0){
        asw.push_back(ind);
        visit[ind] = 1;
        dp(ind+1, adj, asw, visit);
    }else{
        bool val = true;
        for(auto it : adj[ind]){
            if(visit[it]){
                val = false;
                break;
            }
        } 

        if(val){
            visit[ind] = 1;
            asw.push_back(ind);
            dp(ind+1, adj, asw, visit);
        }
    }
}

int main(){
    int t;
    cin >> t;

    while(t--){
        save = {0, vector<int>(0)};
        cin >> n >> m;

        vector<vector<int>> adj(n+1); 
        for(int i = 0; i != m; i++){
            int a, b;
            cin >> a >> b;
    
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        
        vector<int> asw, visit(n+1);
        dp(1, adj, asw, visit);

        cout << save.second.size() << endl;
        for(int i = 0; i != save.second.size(); i++){
            if(i != 0){
                cout << " ";
            }
            cout << save.second[i];
        }
        cout << endl;
    }
}
