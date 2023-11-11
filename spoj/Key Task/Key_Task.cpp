#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int r, c;

int nl(char chr , int level){
    if(chr == 'b'){
        return (level | 1);
    }else if(chr == 'y'){
        return (level | 2);
    }else if(chr == 'r'){
        return (level | 4);
    }else if(chr == 'g'){
        return (level | 8);
    }

    return level;
}

bool val(char chr, int level){
    if(chr == 'B'){
        return level & 1;
    }else if(chr == 'Y'){
        return level & 2;
    }else if(chr == 'R'){
        return level & 4;
    }else if(chr == 'G'){
        return level & 8;
    }

    return true;
}

void bfs(vector<vector<char> > &mat, vector<vector<vector<int> > > &dist, pair<int, int> start){
    queue<pair<int, pair<int, int> > > q;
    q.push(make_pair(0, start));
    dist[0][start.first][start.second] = 0;

    while(!q.empty()){
        pair<int, int> no = q.front().second;
        int level = q.front().first;
        q.pop();

        if(no.first>0 && mat[no.first-1][no.second] != '#'){
            if(dist[level][no.first-1][no.second] == -1 && val(mat[no.first-1][no.second], level)){
                int next_level = nl(mat[no.first-1][no.second], level);
                q.push(make_pair(next_level, make_pair(no.first-1, no.second)));
                dist[next_level][no.first-1][no.second] = dist[level][no.first-1][no.second] = dist[level][no.first][no.second]+1;
            }
        }
        if(no.first+1<r && mat[no.first+1][no.second] != '#'){
            if(dist[level][no.first+1][no.second] == -1 && val(mat[no.first+1][no.second], level)){
                int next_level = nl(mat[no.first+1][no.second], level);
                q.push(make_pair(next_level, make_pair(no.first+1, no.second)));
                dist[next_level][no.first+1][no.second] = dist[level][no.first+1][no.second] = dist[level][no.first][no.second]+1;
            }
        }
        if(no.second>0 && mat[no.first][no.second-1] != '#'){
            if(dist[level][no.first][no.second-1] == -1 && val(mat[no.first][no.second-1], level)){
                int next_level = nl(mat[no.first][no.second-1], level);
                q.push(make_pair(next_level, make_pair(no.first, no.second-1)));
                dist[next_level][no.first][no.second-1] = dist[level][no.first][no.second-1] = dist[level][no.first][no.second]+1;
            }
        }
        if(no.second+1<c && mat[no.first][no.second+1] != '#'){
            if(dist[level][no.first][no.second+1] == -1 && val(mat[no.first][no.second+1], level)){
                int next_level = nl(mat[no.first][no.second+1], level);
                q.push(make_pair(next_level, make_pair(no.first, no.second+1)));
                dist[next_level][no.first][no.second+1] = dist[level][no.first][no.second+1] = dist[level][no.first][no.second]+1;
            }
        }
    }
}

int main(){
    while(cin >> r >> c){
        if(!r && !c){
            break;
        }

        vector<vector<char> > mat(r, vector<char>(c));
        vector<pair<int, int> > saida;
        pair<int, int> start;

        for(int i = 0; i != r; i++){
            for(int j = 0; j != c; j++){
                cin >> mat[i][j];
                if(mat[i][j] == 'X'){
                    saida.push_back(make_pair(i, j));
                }else if(mat[i][j] == '*'){
                    start = make_pair(i, j);
                }
            }
        }

        vector<vector<vector<int> > > dist(16, vector<vector<int> > (r, vector<int> (c, -1)));
        bfs(mat, dist, start);

        int mn = 1e9;
        for(auto it : saida){
            for(int i = 0; i != 16; i++){
                if(dist[i][it.first][it.second] != -1){
                    mn = min(mn, dist[i][it.first][it.second]);
                }
            }
        }

        if(mn == 1e9){
            cout << "The poor student is trapped!" << endl;
        }else{
            cout << "Escape possible in "<<mn<<" steps." << endl;
        }
    }
}