#include <iostream>
#include <vector>
#include <set>
#include <deque>

using namespace std;

void djk(vector<vector<pair<int, int> > > &adj, vector<int> &dist, int start, vector<int> &last){
    set<pair<int, int> > st;
    st.insert(make_pair(0, start));
    dist[start] = 0;

    while(!st.empty()){
        int no = (*st.begin()).second;
        int cost = (*st.begin()).first;

        st.erase(st.begin());
        for(auto it : adj[no]){
            if(it.second + cost < dist[it.first]){
                last[it.first] = no;
                dist[it.first] = it.second+cost;
                st.insert(make_pair(dist[it.first], it.first));
            }
        }
    }
}

int main(){
    int n, s, e;
    int test = 1;
    while(cin >> n >> s >> e){
        if(test != 1){
            cout << endl;
        }
        test++;

        int m;
        cin >> m;

        vector<vector<pair<int, int> > > adj(n+1);
        for(int i = 0; i != m; i++){
            int a, b, c;
            cin >> a >> b >> c;

            adj[a].push_back(make_pair(b, c));
            adj[b].push_back(make_pair(a, c));
        }

        vector<int> dist1(n+1, 1e9), dist2(n+1, 1e9), last1(n+1), last2(n+1);
        djk(adj, dist1, s, last1);
        djk(adj, dist2, e, last2);

        int mn = 1e9;
        pair<int, int> com;
        cin >> m;
        for(int i = 0; i != m; i++){
            int a, b, c;
            cin >> a >> b >> c;

            int sum = dist1[a];
            sum += dist2[b];
            sum += c;

            if(mn > sum){
                com = make_pair(a, b);
                mn = sum;
            }

            sum = dist1[b];
            sum += dist2[a];
            sum += c;

            if(mn > sum){
                com = make_pair(b, a);
                mn = sum;
            }
        }

        deque<int> dq;
        if(mn < dist1[e]){
            int no = com.first;
            while(no != 0){
                dq.push_front(no);
                no = last1[no];
            }

            no = com.second;
            while(no != 0){
                dq.push_back(no);
                no = last2[no];
            }

            for(int i = 0; i != dq.size(); i++){
                if(i == dq.size()-1){
                    cout << dq[i] << endl;
                    break;
                }
                cout << dq[i] << " ";
            }

            cout << com.first << endl;
            cout << mn << endl;
        }else{
            int no = e;
            while(no != 0){
                dq.push_front(no);
                no = last1[no];
            }

            for(int i = 0; i != dq.size(); i++){
                if(i == dq.size()-1){
                    cout << dq[i] << endl;
                    break;
                }
                cout << dq[i] << " ";
            }

            cout << "Ticket Not Used" << endl;
            cout << dist1[e] << endl;
        }
    }
}

