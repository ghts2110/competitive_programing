#include <iostream>
#include <vector>
#include <cmath>
#include <stack>

using namespace std;

int add_adj(vector<pair<int, int> > &loc, int no, int adj){
    double dist = 1e9;
    int n = -1;
    for(int i = 0; i != loc.size(); i++){
        if(i != no && i != adj){
            int l1 = abs(loc[i].first-loc[no].first);
            l1 *= l1;
            int l2 = abs(loc[i].second-loc[no].second);
            l2 *= l2;

            if(dist > sqrt(l1+l2)){
                dist = sqrt(l1+l2);
                n = i;
            }else if(dist == sqrt(l1+l2)){
                if(loc[n] > loc[i]){
                    dist = sqrt(l1+l2);
                    n = i;
                }
            }
        }
    }

    return n;
}

int main(){
    int n;
    while(cin >> n){
        if(n == 0){
            break;
        }

        vector<pair<int, int> > loc;
        for(int i = 0; i != n ;i++){
            int x, y;
            cin >> x >> y;
            loc.push_back(make_pair(x, y));
        }
        vector<vector<int> > adj(n);
        adj[0].push_back(add_adj(loc, 0, -1));
        adj[adj[0][0]].push_back(0);
        adj[0].push_back(add_adj(loc, 0, adj[0][0]));
        adj[adj[0][1]].push_back(0);

        stack<int> st;
        st.push(adj[0][0]);
        st.push(adj[0][1]);

        while(!st.empty()){
            int no = st.top();
            st.pop();

            if(adj[no].size() == 2){
                continue;
            }

            int nw_no = add_adj(loc, no, adj[no][0]);
            if(adj[nw_no].size() < 2){
                adj[no].push_back(nw_no);
                adj[nw_no].push_back(no);
                st.push(nw_no);
            }
        }

        bool val = true;
        for(int i = 0; i != adj.size(); i++){
            if(adj[i].size() == 0){
                val = false;
            }
        }

        if(val){
            cout << "All stations are reachable." << endl;
        }else{
            cout << "There are stations that are unreachable." << endl;
        }
    }
}