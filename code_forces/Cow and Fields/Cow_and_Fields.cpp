#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> bfs(int n, vector<vector<int> > &adj, int start){
    queue<int> q;
    q.push(start);
    vector<int> dist(n+1, 1e9);
    dist[start] = 0;

    while(!q.empty()){
        int no = q.front();
        q.pop();

        for(auto it : adj[no]){
            if(dist[it] == 1e9){
                dist[it] = dist[no]+1;
                q.push(it);
            }
        }
    }

    return dist;
}

int main(){
    int n, m, k;
    while(cin >> n >> m >> k){
        vector<int> sp(k);
        for(int i = 0; i != k; i++){
            cin >> sp[i];
        }

        vector<vector<int> > adj(n+1);
        for(int i = 0; i != m; i++){
            int a, b;
            cin >> a >> b;

            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        vector<int> dist1 = bfs(n, adj, 1);
        vector<int> distN = bfs(n, adj, n);

        vector<pair<int, int> > v;
        for(auto it : sp){
           v.push_back(make_pair(dist1[it]-distN[it], it));
        }

        sort(v.begin(), v.end());
        int ans=0, tmp=0;
        for(int i = 0; i != v.size(); i++){
            if(i!=0){
                ans=max(ans,tmp+distN[v[i].second]+1);
            }
            tmp=max(tmp,dist1[v[i].second]);
        }
        cout<<min(ans,dist1[n]) << endl;
    }
}