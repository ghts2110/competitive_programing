#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main(){
    int n, m;
    while(cin >> n >> m){

        vector<vector<pair<int, long long> > > adj(n+1);
        for(int i = 0; i != m; i++){
            int a, b, c;
            cin >> a >> b >> c;

            adj[a].push_back(make_pair(b, c));
            adj[b].push_back(make_pair(a, c));
        }

        vector<long long> dist(n+1, 1e18);
        vector<int> asw(n+1);
        set<pair<long long, int> > s;
        dist[1] = 0;
        s.insert(make_pair(0, 1));

        while(!s.empty()){
            int no = (*s.begin()).second;
            long long cost = (*s.begin()).first;

            s.erase(s.begin());
            for(auto it: adj[no]){
                if(dist[it.first] > cost+it.second){
                    dist[it.first] = cost+it.second;
                    asw[it.first] = no;
                    s.insert(make_pair(cost+it.second, it.first));
                }
            }
        }

        if(dist[n] == 1e18){
            cout << -1 << endl;
            continue;
        }

        vector<int> v;
        int no = n;
        while(no != 0){
            v.push_back(no);
            no = asw[no];
        }

        for(int i = v.size()-1; i != -1; i--){
            if(i == 0){
                cout << v[i] << endl;
                break;
            }
            cout << v[i] << " ";
        }
    }
}