#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(){
    int n;
    while(cin >> n){
        vector<vector<int> > adj(n+1);
        for(int i = 0; i != n-1; i++){
            int a, b;
            cin >> a >> b;

            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        vector<int> visit(n+1, -1);
        visit[1] = 0;
        queue<int> q;
        q.push(1);

        while(!q.empty()){
            int save = q.front();
            q.pop();

            for(auto it : adj[save]){
                if(visit[it] == -1){
                    q.push(it);
                    visit[it] = visit[save]+1;
                }
            }
        }

        int mx = 0, index;
        for(int i = 1; i != visit.size(); i++){
            if(visit[i] > mx){
                index = i;
                mx = visit[i];
            }
            visit[i] = -1;
        }

        q.push(index);
        visit[index] = 0;

        while(!q.empty()){
            int save = q.front();
            q.pop();

            for(auto it : adj[save]){
                if(visit[it] == -1){
                    q.push(it);
                    visit[it] = visit[save]+1;
                }
            }
        }

        mx = 0;
        for(int i = 1; i != visit.size(); i++){
            if(visit[i] > mx){
                mx = visit[i];
            }
            visit[i] = -1;
        }

        cout << mx << endl;
    }
}