#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(){
    int n, m;
    while(cin >> n >> m){
        vector<vector<int> > adj(n+1);
        for(int i = 0; i != n-1; i++){
            int a, b;
            cin >> a >> b;

            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        vector<int> asw(n+1);
        while(m--){
            int a, b, c;
            cin >> a >> b >> c;

            vector<int> visit(n+1, -1);
            queue<int> q;
            q.push(a);
            visit[a] = 0;

            while(!q.empty()){
                int no = q.front();
                q.pop();

                for(auto it : adj[no]){
                    if(visit[it] == -1){
                        visit[it] = no;
                        q.push(it);
                    }
                }
            }

            int vst = b;
            while(vst != 0){
                asw[vst] = c;
                vst = visit[vst];
            }
        }

        for(int i = 1; i != asw.size(); i++){
            if(i == asw.size()-1){
                cout << asw[i] << endl;
                break;
            }
            cout << asw[i] << " ";
        }
    }
}