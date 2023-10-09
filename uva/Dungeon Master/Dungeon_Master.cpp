#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(){
    int a, b, c;
    while(cin >> a >> b >> c){
        if(!a && !b && !c){
            break;
        }

        vector<vector<vector<char> > > v(a, vector<vector<char> > (b, vector<char> (c)));

        for(int i = 0; i != a; i++){
            for(int j = 0; j != b; j++){
                for(int k = 0; k != c; k++){
                    cin >> v[i][j][k];
                }
            }
        }

        int cont = -1, s, e;
        vector<vector<int> > adj(c*a*b);
        for(int i = 0; i != a; i++){
            for(int j = 0; j != b; j++){
                for(int k = 0; k != c; k++){
                    cont++;

                    if(v[i][j][k] == 'S'){
                        s = cont;
                    }else if(v[i][j][k] == 'E'){
                        e = cont;
                    }

                    if(i>0 && v[i-1][j][k] != '#'){
                        adj[cont].push_back(cont-(b*c));
                    }
                    if(i+1<a && v[i+1][j][k] != '#'){
                        adj[cont].push_back(cont+(b*c));
                    }
                    if(j>0 && v[i][j-1][k] != '#'){
                        adj[cont].push_back(cont-c);
                    }
                    if(j+1<b && v[i][j+1][k] != '#'){
                        adj[cont].push_back(cont+c);
                    }
                    if(k>0 && v[i][j][k-1] != '#'){
                        adj[cont].push_back(cont-1);
                    }
                    if(k+1<c && v[i][j][k+1] != '#'){
                        adj[cont].push_back(cont+1);
                    }
                }
            }
        }

        vector<int> dist(a*b*c, -1);
        dist[s] = 0;
        queue<int> q;
        q.push(s);

        while(!q.empty()){
            int no = q.front();
            q.pop();

            for(auto it : adj[no]){
                if(dist[it] == -1){
                    dist[it] = dist[no]+1;
                    q.push(it);
                }
            }
        }

        if(dist[e] == -1){
            cout << "Trapped!" << endl;
        }else{
            cout << "Escaped in "<<dist[e]<<" minute(s)." << endl;
        }

    }
}
