#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void bfs(vector<vector<int>> &v, int x, int y){
    v[x][y] = 0;    
    queue<pair<int, int>> q;
    q.push({x, y});
    
    while(!q.empty()){
        pair<int, int> no = q.front();
        q.pop();
        
        if(no.first-2 >= 0){
            if(no.second-1 >= 0 && v[no.first-2][no.second-1] == -1){
                q.push({no.first-2, no.second-1});
                v[no.first-2][no.second-1] = v[no.first][no.second] +1;
            }
            if(no.second+1 < 8 && v[no.first-2][no.second+1] == -1){
                q.push({no.first-2, no.second+1});
                v[no.first-2][no.second+1] = v[no.first][no.second] +1;

            }
        }
        if(no.first+2 < 8){
            if(no.second-1 >= 0 && v[no.first+2][no.second-1] == -1){
                q.push({no.first+2, no.second-1});
                v[no.first+2][no.second-1] = v[no.first][no.second] +1;

            }
            if(no.second+1 < 8 && v[no.first+2][no.second+1] == -1){
                q.push({no.first+2, no.second+1});
                v[no.first+2][no.second+1] = v[no.first][no.second] +1;
            }
        }
        if(no.second-2 >= 0){
            if(no.first-1 >= 0 && v[no.first-1][no.second-2] == -1){
                q.push({no.first-1, no.second-2});
                v[no.first-1][no.second-2] = v[no.first][no.second] +1;
            }
            if(no.first+1 < 8 && v[no.first+1][no.second-2] == -1){
                v[no.first+1][no.second-2] = v[no.first][no.second] +1;
                q.push({no.first+1, no.second-2});
            }
        }
        if(no.second+2 < 8){
            if(no.first-1 >= 0 && v[no.first-1][no.second+2] == -1){
                v[no.first-1][no.second+2] =v[no.first][no.second] +1;
                q.push({no.first-1, no.second+2});
            }
            if(no.first+1 < 8 && v[no.first+1][no.second+2] == -1){
                v[no.first+1][no.second+2] = v[no.first][no.second] +1;
                q.push({no.first+1, no.second+2});
            }
        }
    }
}

int main(){
    char c1, c2;
    int n1, n2;

    while(cin >> c1 >> n1 >> c2 >> n2){
        vector<vector<int>> v(8, vector<int>(8, -1));
        bfs(v, c1-'a', n1-1);
        cout << "To get from "<<c1<<""<<n1<<" to "<< c2<<""<< n2 <<" takes "<< v[c2-'a'][n2-1] <<" knight moves." << endl;
    }
}
