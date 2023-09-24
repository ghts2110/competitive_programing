#include <iostream>
#include <vector>
#include <cstdio>
#include <queue>

using namespace std;

int n, m, start, finish, asw;

void dijkstra(vector<vector<pair<int, int> > > &adj, vector<vector<int> > &path){
    priority_queue<pair<int, int> > pq;
    pq.push(make_pair(0, start));

    vector<int> dist(n, 1e9);
    dist[start] = 0;

    int node, cost;
    while (!pq.empty()){
        cost = pq.top().first;
        node = pq.top().second;

        pq.pop();

        for (int i = 0; i < adj[node].size(); i++){
            int newn = adj[node][i].first;
            int newc = adj[node][i].second;

            if (cost + newc <= dist[newn] && newc != -1){
                if (cost + newc < dist[newn]){
                    path[newn].clear();
                }

                path[newn].push_back(node);

                dist[newn] = cost + newc;
                pq.push(make_pair(dist[newn], newn));
            }
        }
    }

    asw = dist[finish];
}

void remove(int node, vector<vector<int> > &path, vector<vector<pair<int, int> > > &adj){
    for (int i = 0; i < path[node].size(); i++){
        int neigh = path[node][i];
        for(auto & it : adj[neigh]){
            if(it.first == node){
                it.second = -1;
                break;
            }
        }
        remove(neigh, path, adj);
    }
}

int main(){
    while (scanf("%d %d", &n, &m)){
        if(!n && !m){
            break;
        }

        scanf("%d %d", &start, &finish);

        vector<vector<pair<int, int> > > adj(n);
        vector<vector<int> > path(n);

        int a, b, c;
        for (int i = 0; i < m; i++){
            scanf("%d %d %d", &a, &b, &c);
            adj[a].push_back(make_pair(b, c));
        }

        dijkstra(adj, path);
        remove(finish, path, adj);
        dijkstra(adj, path);

        if(asw == 1e9){
            printf("-1\n");
        }else{
            printf("%d\n", asw);
        }
    }
}