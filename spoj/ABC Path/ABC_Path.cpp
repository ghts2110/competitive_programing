#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

int h, w;

bool val1(int x, int y){
    if(x < 0 || y < 0){
        return false;
    }
    if(x >= h || y >= w){
        return false;
    }

    return true;
}

bool val2(char c1, char c2){
    if(c1 == char(c2-1)){
        return true;
    }

    return false;
}

int main(){
    pair<int, int> p[] = {make_pair(-1, -1), make_pair(-1, 0), make_pair(-1, 1),
                          make_pair(0, -1), make_pair(0, 1),
                          make_pair(1, -1), make_pair(1, 0), make_pair(1, 1)};

    int test = 1;
    while(scanf("%d %d", &h, &w)){
        if(!h && !w){
            break;
        }

        vector<vector<char> > mat(h, vector<char>(w));
        vector<pair<int, int> > v;
        for(int i = 0; i != h; i++){
            for(int j = 0; j != w; j++){
                scanf(" %c", &mat[i][j]);
                if(mat[i][j] == 'A'){
                    v.push_back(make_pair(i, j));
                }
            }
        }

        map<pair<int, int>, vector<pair<int, int> > > mp;
        for(int i = 0; i != h; i++){
            for(int j = 0; j != w; j++){
                for(auto it : p){
                    if(val1(i+it.first, j+it.second) && val2(mat[i][j], mat[i+it.first][j+it.second])){
                        mp[make_pair(i, j)].push_back(make_pair(i+it.first, j+it.second));
                    }
                }
            }
        }


        vector<vector<int> > visit(h, vector<int> (w));
        for(auto start : v){
            queue<pair<int,int> > q;
            q.push(start);
            visit[start.first][start.second] = 1;

            while(!q.empty()){
                pair<int, int> no = q.front();
                q.pop();

                for(auto it : mp[no]){
                    if(visit[it.first][it.second] == 0){
                        visit[it.first][it.second] = visit[no.first][no.second]+1;
                        q.push(it);
                    }
                }
            }
        }

        int mx = 0;
        for(auto it : visit){
            for(auto jt : it){
                mx = max(mx, jt);
            }
        }

        printf("Case %d: %d\n", test, mx);
        test++;
    }
}