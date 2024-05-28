#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void bfs(int no, vector<vector<int>> &adj, vector<int> &visit){
    for(auto it : adj[no]){
        if(visit[it] <= visit[no]){
            visit[it] = visit[no]+1;
            bfs(it, adj, visit);
        }
    }
}

int main(){
    int n, m;
    while(cin >> n >> m){
        if(n == 0){
            break;
        }

        vector<vector<int>> adj(n+1);
        for(int i = 0; i != m; i++){
            int x, y;
            cin >> x >> y;
            adj[x].push_back(y);
        }

        vector<int> visit(n+1);
        for(int i = 1; i <= n; i++){
            if(visit[i] == 0){
                bfs(i, adj, visit);
            }
        }

        vector<pair<int, int>> asw;
        for(int i = 1; i <= n; i++){
            asw.push_back({visit[i], i});
        }

        sort(asw.begin(), asw.end());
        for(int i = 0; i != asw.size(); i++){
            if(i != 0){
                cout << " ";
            }
            cout << asw[i].second;
        }

        cout << endl;
    }
}
