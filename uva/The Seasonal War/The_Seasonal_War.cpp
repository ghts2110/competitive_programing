#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void dfs(int i, int j, vector<vector<int>> &v, vector<vector<bool>> &visit){
    visit[i][j] = true;
    if(i+1 < v.size() && v[i+1][j] == 1 && !visit[i+1][j]){
        dfs(i+1, j, v, visit);
    }
    if(i-1 > -1 && v[i-1][j] == 1 && !visit[i-1][j]){
        dfs(i-1, j, v, visit);
    }

    if(j+1 < v.size() && v[i][j+1] == 1 && !visit[i][j+1]){
        dfs(i, j+1, v, visit);
    }
    if(j-1 > -1 && v[i][j-1] == 1 && !visit[i][j-1]){
        dfs(i, j-1, v, visit);
    }
    if(i+1 < v.size() && j+1 < v.size() && v[i+1][j+1] == 1 && !visit[i+1][j+1]){
        dfs(i+1, j+1, v, visit);
    }
    if(i+1 < v.size() && j-1 < v.size() && v[i+1][j-1] == 1 && !visit[i+1][j-1]){
        dfs(i+1, j-1, v, visit);
    }
    if(i-1 > -1 && j+1 < v.size() && v[i-1][j+1] == 1 && !visit[i-1][j+1]){
        dfs(i-1, j+1, v, visit);
    }
    if(i-1 > -1 && j-1 < v.size() && v[i-1][j-1] == 1 && !visit[i-1][j-1]){
        dfs(i-1, j-1, v, visit);
    }
}
int main(){
    int n;
    int test = 1;
    while(cin >> n){
    
        vector<vector<int>> v(n, vector<int>(n));
        for(int i = 0; i != n; i++){
            for(int j = 0; j != n; j++){
                char c;
                cin >> c;
                v[i][j] = c-'0';
            }
        }

        vector<vector<bool>> visit(n, vector<bool>(n, false));
        int asw = 0;
        for(int i = 0; i != n; i++){
            for(int j = 0; j != n; j++){
                if(v[i][j] == 1 && !visit[i][j]){
                    asw++;
                    dfs(i, j, v, visit);
                }
            }
        }

        cout << "Image number "<<test<<" contains "<<asw<<" war eagles." << endl;
        test++;
    }
}
