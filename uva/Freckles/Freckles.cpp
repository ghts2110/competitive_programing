#include <iostream>
#include <vector>
#include <cmath>
#include <set>

using namespace std;

double dist(pair<double, double> a, pair<double, double> b){
    return sqrt((a.first-b.first) * (a.first-b.first) + (a.second-b.second) * (a.second-b.second));
}

int main(){
    int t;
    cin >> t;

    bool f = true;
    while(t--){
        if(!f){
            cout << endl;
        }
        f=false;
        int n;
        cin >> n;

        vector<pair<double, double>> v;
        for(int i = 0; i != n; i++){
            double x, y;
            scanf("%lf %lf", &x, &y);
            v.push_back({x, y});
        }

        set<pair<double, pair<int, int>>> st;
        vector<vector<pair<double, int>>> adj(n);
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                double d = dist(v[i], v[j]);
                if(i == 0){
                    st.insert({d, {i, j}});
                }
        
                adj[i].push_back({d, j});
                adj[j].push_back({d, i});
            }
        }

        double asw = 0;
        vector<bool> visit(n);
        while(!st.empty()){
            int n1 = (*st.begin()).second.first;
            int n2 = (*st.begin()).second.second;
            double c = (*st.begin()).first;
            
            st.erase(st.begin());
            if(visit[n1] && visit[n2]){
                continue;
            }

            for(auto it : adj[n2]){
                if(visit[it.second]){
                    continue;
                }
                st.insert({it.first, {n2, it.second}});
            }

            visit[n1] = visit[n2] = true;
            asw += c;
        }
        
        printf("%.2lf\n", asw);
    }
}
