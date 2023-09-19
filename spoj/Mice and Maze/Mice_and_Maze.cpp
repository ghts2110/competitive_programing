#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(){
    int n;
   cin >> n;
    int e, t;
    cin >> e >>t;
    int m;
    cin >> m;

    vector<vector<pair<int, int> > > adj(n+1);
    for(int i = 0; i != m; i++){
        int x, y, z;
        cin >> x >> y >> z;
        adj[x].push_back(make_pair(y, z));
    }


    priority_queue<pair<int, pair<int, int> > > pq;

    int asw = 0;
    for(int i = 1; i <= n; i++){
        vector<int> dist(n+1, 1e9);
        pq.push(make_pair(0, make_pair(i, i)));
        while(!pq.empty()){
            int save = pq.top().second.second;

            if(pq.top().first < dist[save]){
                dist[save] = pq.top().first;
                pq.pop();
                for(auto it : adj[save]){
                    pq.push(make_pair(dist[save] + it.second, make_pair(save, it.first)));
                }
            }else{
                pq.pop();
            }
        }

        if(dist[e] <= t){
            asw++;
        }
    }

    cout << asw << endl;
}