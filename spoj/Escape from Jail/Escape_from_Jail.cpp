#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(){
    int n, k, m;
    while(cin >> n >> k >> m){
        if(n == -1){
            break;
        }

        vector<int> kay_door(n+1);
        vector<bool> is_door(n+1, false), is_kay(n+1, false), push_door(n+1, false);

        for(int i = 0; i != k; i++){
            int a, b;
            cin >> a >> b;

            is_door[b] = true;
            is_kay[a] = true;
            kay_door[a] = b;
        }

        vector<vector<int> > adj(n+1);
        for(int i = 0; i != m; i++){
            int a, b;
            cin >> a >> b;

            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        queue<int> q;
        vector<int> dist(n+1, -1);

        q.push(1);
        dist[1] = 0;

        int last = 0;
        while(!q.empty()){
            int no =  q.front();
            q.pop();

            last = no;

            if(is_door[no]){
                q.push(no);
                continue;
            }

            for(auto it : adj[no]){
                if(dist[it] == -1){
                    if(is_kay[it]){
                        is_door[kay_door[it]] = false;
                        if(push_door[kay_door[it]]){
                            q.push(kay_door[it]);
                        }
                    }

                    if(is_door[it]){
                        push_door[it] = true;
                        continue;
                    }

                    dist[it] = dist[no]+1;
                    q.push(it);
                }
            }
        }

        if(dist[n] == -1){
            cout << "N" << endl;
        }else{
            cout << "Y" << endl;
        }


    }
}