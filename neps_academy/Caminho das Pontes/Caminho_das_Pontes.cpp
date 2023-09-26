#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main(){
    int n, m;
    while(cin >> n >> m){
        vector<vector<pair<int, int> > > adj(n+2);
        for(int i = 0; i != m; i++){
            int a, b, c;
            cin >> a >> b >> c;

            adj[a].push_back(make_pair(b, c));
            adj[b].push_back(make_pair(a, c));
        }

        set<pair<int, int> > s;
        s.insert(make_pair(0, 0));
        vector<int> dist(n+2, 1e9);

        while(!s.empty()){
            int no = (*s.begin()).second;
            int cost = (*s.begin()).first;

            s.erase(s.begin());

            if(cost < dist[no]){
                dist[no] = cost;
                for(auto it : adj[no]){
                    s.insert(make_pair(it.second+cost, it.first));
                }
            }
        }

        cout << dist[n+1] << endl;
    }

}