#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

void bfs(int s, map<int, vector<int>> &adj, map<int, int> &visit){
    queue<int> q;
    q.push(s);
    visit[s] = 0;

    while(!q.empty()){
        int no = q.front();
        q.pop();

        for(auto it : adj[no]){
            if(visit[it] == -1){
                visit[it] = visit[no]+1;
                q.push(it);
            }
        }
    }
}

int main(){
    int n;
    int test = 1;
    while(cin >> n){
        if(!n){
            break;
        }

        map<int, vector<int>> adj;
        for(int i = 0; i != n; i++){
            int a, b;
            cin >> a >> b;

            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        int a, b;
        while(cin >> a >> b){
            if(!a && !b){
                break;
            }

            map<int, int> visit;
            for(auto it : adj){
                visit[it.first] = -1;
            }

            bfs(a, adj, visit);

            int cont = 0;
            for(auto it: adj){
                if(visit[it.first] > b || visit[it.first] == -1){
                    cont++;
                }
            }

            cout << "Case "<<test<<": "<<cont<<" nodes not reachable from node "<<a<<" with TTL = "<<b<<"." << endl;
            test++;
        }
    }
}
