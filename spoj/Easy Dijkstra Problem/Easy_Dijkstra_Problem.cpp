#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main(){
    int t;
    scanf("%d", &t);

    while(t--){
        int n, m;
        scanf("%d %d", &n, &m);

        vector<vector<pair<int, int> > > adj(n+1);
        for(int i = 0; i != m; i++){
            int a, b, c;
            scanf("%d %d %d", &a, &b, &c);

            adj[a].push_back(make_pair(b, c));
        }

        int s, f;
        scanf("%d %d", &s, &f);

        set<pair<int, int> > st;
        vector<int> dist(n+1,1e9);
        st.insert(make_pair(0, s));

        while(!st.empty()){
            int no = (*st.begin()).second;
            int cost = (*st.begin()).first;

            st.erase(st.begin());
            if(cost < dist[no]){
                dist[no] = cost;

                for(auto it : adj[no]){
                    st.insert(make_pair(it.second+cost, it.first));
                }
            }
        }

        if(dist[f] == 1e9){
            printf("NO\n");
        }else{
            printf("%d\n", dist[f]);
        }
    }
}