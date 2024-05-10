#include <iostream>
#include <vector>

using namespace std;
int m, n;

void bfs(int i, int j, vector<vector<char>> &v, vector<vector<bool>> &visit){
    visit[i][j] = true;
    if(i-1>=0 && v[i-1][j] == '@' && !visit[i-1][j]){
        bfs(i-1, j, v, visit);
    }
    if(i+1 < n && v[i+1][j] == '@' && !visit[i+1][j]){
        bfs(i+1, j, v, visit);
    }
    if(j-1>=0 && v[i][j-1] == '@' && !visit[i][j-1]){
        bfs(i, j-1, v, visit);
    }
    if(j+1 < m && v[i][j+1] == '@' && !visit[i][j+1]){
        bfs(i, j+1, v, visit);
    }
    if(i-1 >= 0 && j-1 >= 0 && v[i-1][j-1] == '@' && !visit[i-1][j-1]){
        bfs(i-1, j-1, v, visit);
    }
    if(i-1 >= 0 && j+1 < m && v[i-1][j+1] == '@' && !visit[i-1][j+1]){
        bfs(i-1, j+1, v, visit);
    }
    if(i+1 < n && j-1 >= 0 && v[i+1][j-1] == '@' && !visit[i+1][j-1]){
        bfs(i+1, j-1, v, visit);
    }
    if(i+1 < n && j+1 < m && v[i+1][j+1] == '@' && !visit[i+1][j+1]){
        bfs(i+1, j+1, v, visit);
    }


}

int main(){
    while(cin >> n >> m){
        if(!n && !m){
            break;
        }
        
        vector<vector<char>> v(n, vector<char>(m));
        for(int i = 0; i != n; i++){
            for(int j = 0; j != m; j++){
                cin >> v[i][j];
            }
        }

        vector<vector<bool>> visit(n, vector<bool>(m));
        int asw = 0;
        for(int i = 0; i != n; i++){
            for(int j = 0; j != m; j++){
                if(v[i][j] == '@' && !visit[i][j]){
                    asw ++;
                    bfs(i, j, v, visit);
                }
            }
        }

        cout << asw << endl;
    }
}
