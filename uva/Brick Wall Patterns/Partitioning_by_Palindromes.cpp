#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

void bfs(vector<vector<int>> &adj, int start, vector<int> &dist){
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
    int n;
    cin >> n;

    while(n--){
        string s;
        cin >> s;


        vector<vector<int>> adj(s.size()+1);
        for(int i =0 ; i != s.size(); i++){
            int l = i;
            int r = i;

            while(l >= 0 && r <= s.size() && s[l] == s[r]){
                adj[l].push_back(r+1);
                l--;
                r++;
            }
        }

        for(int i = 0; i != s.size(); i++){
            int l = i; 
            int r = i+1;

            while(l >= 0 && r <= s.size() && s[l] == s[r]){
                adj[l].push_back(r+1);
                l--;
                r++;
            }
        }

        vector<int> dist(s.size()+1, -1);
        bfs(adj, 0, dist);

        cout << dist[s.size()] << endl;
    }

}
