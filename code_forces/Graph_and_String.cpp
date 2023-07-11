#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <bitset>

#define pb push_back

using namespace std;

int main(){
    int n, m;
    string s;   
    
    cin >> n >> m;
    vector<bitset<501> > adj(n+1);
    map<int, int> mp;

    for(int i = 0; i != n; i++){
        s += 'v';
    }

    for(int i = 1; i <= m; i++){
        int u, v;
        cin >> u >> v;

        adj[u][u] = 1;
        adj[u][v] = 1;
        adj[v][u] = 1;
        adj[v][v] = 1;

        mp[u]++;
        mp[v]++;
    }

    for(int i = 1; i <=n ; i++){
        if(mp[i] == n-1){
            s[i-1] = 'b';
        }
    }

    int cont = 0;
    for(int i = 1; i <= n; i++){
        if(mp[i] != n-1 && s[i-1] == 'v'){
            char c;
            if(cont == 0){
                c = 'a';
            }else{
                c = 'c';
            }

            s[i-1] = c;

            for(int j = 1; j <= n; j++){
                if(adj[i][j] && s[j-1] == 'v' && adj[i] == adj[j]){
                    s[j-1] = c;
                    mp[j] = n-1;
                }
            }
            
            cont++;
        }

        if(cont == 2){
            break;
        }
    }

    for(int i = 0; i != s.size(); i++){
        if(s[i] == 'v'){
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;
    cout << s << endl;
}

