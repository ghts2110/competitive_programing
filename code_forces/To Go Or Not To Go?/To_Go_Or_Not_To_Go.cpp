#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int mat[2000][2000];

void bfs(int start, vector<long long> &dist, vector<vector<int> > &adj){
    queue<int> q;
    dist[start] = 0;
    q.push(start);

    while(!q.empty()){
        int no = q.front();
        q.pop();

        for(auto it : adj[no]){
            if(dist[it] == -1){
                dist[it] = dist[no]+1;
                q.push(it);
            }
        }
    }
}

int main(){
    int n, m, w;

    scanf("%d %d %d", &n, &m, &w);

    vector<pair<int, int> > portal;
    vector<vector<int> > adj(n*m);

    for(int i = 0;i != n; i++){
        for(int j = 0; j != m; j++){
            scanf("%d", &mat[i][j]);
        }
    }

    int cont = -1;
    for(int i = 0; i != n; i++){
        for(int j = 0; j != m; j++){
            cont++;
            if(mat[i][j] == -1){
                continue;
            }

            if(mat[i][j] != 0){
                portal.push_back(make_pair(mat[i][j], cont));
            }

            if(i-1>=0 && mat[i-1][j] != -1){
                adj[cont].push_back(cont-m);
            }
            if(i+1<n && mat[i+1][j] != -1){
                adj[cont].push_back(cont+m);
            }
            if(j-1>=0 && mat[i][j-1] != -1){
                adj[cont].push_back(cont-1);
            }
            if(j+1<m && mat[i][j+1] != -1){
                adj[cont].push_back(cont+1);
            }
        }
    }
    vector<long long> d1(n*m, -1), d2(n*m, -1);
    bfs(0, d1, adj);
    bfs(n*m-1, d2, adj);

    long long asw = d1[n*m-1];
    if(asw != -1){
        asw *= w;
    }

    long long mn1 = 1e18, mn2 = 1e18;

    for(auto it : portal){
        if(d1[it.second] == -1){
            continue;
        }

        d1[it.second] *= w;
        d1[it.second] += it.first;

        mn1 = min(mn1, d1[it.second]);
    }
    for(auto it : portal){
        if(d2[it.second] == -1){
            continue;
        }

        d2[it.second] *= w;
        d2[it.second] += it.first;

        mn2 = min(mn2, d2[it.second]);
    }

    if(asw == -1 || asw > mn1 + mn2){
        if(mn1 != 1e18 && mn2 != 1e18){
            asw = mn1 + mn2;
        }
    }

    cout << asw << endl;
}