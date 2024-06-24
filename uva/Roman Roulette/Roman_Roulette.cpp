#include <iostream>
#include <vector>

using namespace std;

int fj(vector<pair<pair<int, int>, pair<int, int>>> adj, int i, int k, int n){
    int cont = n; 
    int ind = i;
    bool val = true;
    int save;
    i = 1;
    while(cont != 1){
        i++;
        ind = adj[ind].second.second;
   
        if(!val && ind == save){
            i--;
            continue;
        }

        if(i == k){
            if(val){
                if(adj[ind].first.second == 1){
                    return 0;
                }

                save = ind;
                val = false;
                cont--;
            }else{
                adj[save].first.second = adj[ind].first.second;
                adj[adj[ind].second.first].second.second = adj[ind].second.second;
                adj[adj[ind].second.second].second.first = adj[ind].second.first;
                val = true;
                ind = adj[save].first.first;
            }
            i = 0;
        }
    }

    return 1;
}

int main(){
    int n, k;
    while(cin >> n >> k){
        if(!n && !k){
            break;
        }

        vector<pair<pair<int, int>, pair<int, int>>> adj(n+1);
        for(int i = 0; i != n; i++){
            adj[i+1].second.second = i+2;
            adj[i+1].second.first = i;
            adj[i+1].first.first = i+1;
            adj[i+1].first.second = i+1;
        }
        adj[n].second.second = 1;
        adj[1].second.first = n;

        int i;
        for(i = 1; i != n; i++){
            int num = fj(adj, i, k, n);
            
            if(num == 1){
                break;
            }
        }

        cout << i << endl;

    }
}
