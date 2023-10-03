#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(){
    int t;
    scanf("%d", &t);

    while(t--){
        int n, r, m;
        scanf("%d %d %d", &n, &r, &m);

        vector<vector<int> > adj(n+1);
        for(int i = 0; i != r; i++){
            int a, b;
            scanf("%d %d", &a, &b);

            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        queue<int> q;
        vector<int> dist(n+1);
        bool asw = true;

        for(int i = 0; i != m; i++){
            vector<bool> visit(n+1, true);
            int first, power;
            scanf("%d %d", &first, &power);

            if(dist[first] != 0){
                asw = false;
            }
            dist[first] = 1;
            visit[first
            ] = false;

            q.push(first);

            while(!q.empty() && asw){
                int no = q.front();
                q.pop();

                for(auto it : adj[no]){
                    if(visit[it] && dist[no] < power+1){
                        q.push(it);
                        visit[it] = false;
                        if(dist[it] != 0){
                            asw = false;
                            break;
                        }

                        dist[it] = dist[no] + 1;
                    }
                }
            }
        }
        for(int i = 1; i <= n; i++){
            if(dist[i] == 0){
                asw = false;
            }
        }

        if(asw){
            printf("Yes\n");
        }else{
            printf("No\n");
        }
    }
}