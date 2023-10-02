#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int n, f;

bool validate(int x, int y){
    if(x < 0 || y < 0){
        return false;
    }

    if(x >= n || y >= n){
        return false;
    }

    return true;
}

int main(){
    pair<int, int> p[] = {make_pair(-1, 0),
                          make_pair(0, -1), make_pair(0, 1),
                          make_pair(1, 0)};

    while(cin >> n >> f){
        vector<vector<char> > mat(n, vector<char> (n));

        for(int i = 0; i != n; i++){
            for(int j = 0; j != n; j++){
                cin >> mat[i][j];
            }
        }

        vector<vector<vector<pair<int, int> > > > adj(n, vector<vector<pair<int,int> > > (n));
        for(int i = 0; i != n; i++){
            for(int j = 0; j != n; j++){
                if(mat[i][j]-'0' > f){
                    continue;
                }

                for(auto it : p){
                    if(validate(i+it.first, j+it.second) && mat[i+it.first][j+it.second]-'0' <= f){
                        adj[i][j].push_back(make_pair(i+it.first, j+it.second));
                    }
                }
            }
        }

        vector<vector<bool> > visit(n, vector<bool> (n, true));
        queue<pair<int, int> > q;
        q.push(make_pair(0, 0));
        if(mat[0][0]-'0' > f){
            q.pop();
        }

        visit[0][0] = false;

        while(!q.empty()){
            pair<int, int> no = q.front();
            mat[no.first][no.second] = '*';
            q.pop();

            for(auto it : adj[no.first][no.second]){
                if(visit[it.first][it.second]){
                    visit[it.first][it.second] = false;
                    q.push(make_pair(it.first, it.second));
                }
            }
        }

        for(int i = 0; i != n; i++){
            for(int j = 0; j != n; j++){
                cout << mat[i][j];
            }
            cout << endl;
        }
    }
}