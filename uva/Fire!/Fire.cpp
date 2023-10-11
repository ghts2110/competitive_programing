#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(){
    int t;
    scanf("%d", &t);

    while(t--){
        int r, c;
        scanf("%d %d", &r, &c);

        vector<vector<char> > v(r, vector<char> (c));
        vector<pair<int, int> > fire;
        pair<int, int> start;

        for(int i = 0; i != r; i++){
            for(int j = 0; j != c; j++){
                scanf(" %c", &v[i][j]);

                if(v[i][j] == 'J'){
                    start = make_pair(i, j);
                }

                if(v[i][j] == 'F'){
                    fire.push_back(make_pair(i, j));
                }
            }
        }

        vector<vector<int> > dist(r, vector<int> (c, 0));
        queue<pair<int, int> > q;

        for(auto it : fire){
            q.push(it);
            dist[it.first][it.second] = -1;
        }
        q.push(start);
        dist[start.first][start.second] = 1;

        while(!q.empty()){
            pair<int, int> no = q.front();
            q.pop();

            if(no.first>0 && v[no.first-1][no.second] != '#' && !dist[no.first-1][no.second]){
                if(dist[no.first][no.second] == -1){
                    dist[no.first-1][no.second] = -1;
                }else{
                    dist[no.first-1][no.second] = dist[no.first][no.second]+1;
                }
                q.push(make_pair(no.first-1, no.second));
            }
            if(no.first+1<r && v[no.first+1][no.second] != '#' && !dist[no.first+1][no.second]){
                if(dist[no.first][no.second] == -1){
                    dist[no.first+1][no.second] = -1;
                }else{
                    dist[no.first+1][no.second] = dist[no.first][no.second]+1;
                }
                q.push(make_pair(no.first+1, no.second));
            }
            if(no.second>0 && v[no.first][no.second-1] != '#' && !dist[no.first][no.second-1]){
                if(dist[no.first][no.second] == -1){
                    dist[no.first][no.second-1] = -1;
                }else{
                    dist[no.first][no.second-1] = dist[no.first][no.second]+1;
                }
                q.push(make_pair(no.first, no.second-1));
            }
            if(no.second+1<c && v[no.first][no.second+1] != '#' && !dist[no.first][no.second+1]){
                if(dist[no.first][no.second] == -1){
                    dist[no.first][no.second+1] = -1;
                }else{
                    dist[no.first][no.second+1] = dist[no.first][no.second]+1;
                }
                q.push(make_pair(no.first, no.second+1));
            }
        }

        int mn = 1e9;
        for(int i = 0; i != r; i++){
            if(dist[i][0] > 0 && dist[i][0] < mn){
                mn = dist[i][0];
            }

            if(dist[i][c-1] > 0 && dist[i][c-1] < mn){
                mn = dist[i][c-1];
            }
        }

        for(int i = 0; i < c; ++i) {
            if(dist[0][i] > 0 && dist[0][i] < mn){
                mn = dist[0][i];
            }

            if(dist[r-1][i] > 0 && dist[r-1][i] < mn){
                mn = dist[r-1][i];
            }
        }

        if(mn == 1e9){
            cout << "IMPOSSIBLE" << endl;
        }else{
            cout << mn << endl;
        }
    }
}