#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n;

int main(){
    cin >> n;

    vector<int> v(n), v_odd, v_even;
    vector<vector<int> > adj(n);
    for(int i = 0; i != n; i++){
        cin >> v[i];
        if(v[i]%2==0){
            v_even.push_back(i);
        }else{
            v_odd.push_back(i);
        }

        if(i+v[i]< n){
            adj[i+v[i]].push_back(i);
        }

        if(i-v[i] > -1){
            adj[i-v[i]].push_back(i);
        }
    }

    vector<int> asw(n, -1);
    queue<int> q;
    vector<int> dist(n, 1e9);
    for(auto it : v_odd){
        q.push(it);
        dist[it] = 0;
    }

    while(!q.empty()){
        int no = q.front();
        q.pop();

        for(auto it : adj[no]){
            if(dist[it] == 1e9){
                dist[it] = dist[no] + 1;
                q.push(it);
            }
        }
    }

    for(auto it : v_even){
        if(dist[it] != 1e9){
            asw[it] = dist[it];
        }
    }

    dist = vector<int> (n, 1e9);
    for(auto it : v_even){
        q.push(it);
        dist[it] = 0;
    }

    while(!q.empty()){
        int no = q.front();
        q.pop();

        for(auto it : adj[no]){
            if(dist[it] == 1e9){
                dist[it] = dist[no] + 1;
                q.push(it);
            }
        }
    }

    for(auto it : v_odd){
        if(dist[it] != 1e9){
            asw[it] = dist[it];
        }
    }

    for(int i = 0; i != n; i++){
        if(i == n-1){
            cout << asw[i] << endl;
            break;
        }

        cout << asw[i] << " ";
    }
}