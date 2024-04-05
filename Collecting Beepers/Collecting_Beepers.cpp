#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;
int x, y;
int n;

int bfs(int sx, int sy, vector<vector<int>> &v){
    vector<vector<vector<int>>> visit((1<<n), vector<vector<int>>(v.size(), vector<int>(v[0].size())));
    queue<pair<int, pair<int, int>>> q;
    
    visit[0][sx][sy] = 0;
    q.push({0, {sx, sy}});

    while(!q.empty()){
        pair<int, int> no = q.front().second;
        int di = q.front().first;
        if(no.first == x && no.second == y && di == (1<<n)-1){
            return visit[di][no.first][no.second];
        }
        q.pop();

        if(no.second+1 < v[0].size() && visit[di][no.first][no.second+1] == 0){
            visit[di | v[no.first][no.second+1]][no.first][no.second+1] = visit[di][no.first][no.second] + 1;
            q.push({di | v[no.first][no.second+1], {no.first, no.second+1}});
        }

        if(no.second-1 >= 0 && visit[di][no.first][no.second-1] == 0){
            visit[di | v[no.first][no.second-1]][no.first][no.second-1] = visit[di][no.first][no.second] + 1;
            q.push({di | v[no.first][no.second-1], {no.first, no.second-1}});
        }

        if(no.first+1 < v.size() && visit[di][no.first+1][no.second] == 0){
            visit[di | v[no.first+1][no.second]][no.first+1][no.second] = visit[di][no.first][no.second]+1;
            q.push({di | v[no.first+1][no.second], {no.first+1, no.second}});
        }

        if(no.first-1 >= 0 && visit[di][no.first-1][no.second] == 0){
            visit[di | v[no.first-1][no.second]][no.first-1][no.second] = visit[di][no.first][no.second]+1;
            q.push({di | v[no.first-1][no.second], {no.first-1, no.second}});
        }
    }

    return -1;
}

int main(){
    int t;
    cin >> t;
    int start_x, start_y;

    while(t--){
        cin >> start_x >> start_y;
        cin >> x >> y;
        x--;
        y--;

        cin >> n;

        map<pair<int, int>, bool> mp;
        int cont = 0;

        mp[{x, y}] = true;
        vector<vector<int>> v(start_x, vector<int> (start_y));
        for(int i = 0; i!= n; i++){
            int px, py;
            cin >> px >> py;
            px--;
            py--;

            if(mp[{px, py}]){
                continue;
            }

            v[px][py] = (1<<cont);
            mp[{px, py}] = true;
            cont++;
        }
        n = cont;
        cout << "The shortest path has length " <<  bfs(x, y, v) << endl;
    }
}
