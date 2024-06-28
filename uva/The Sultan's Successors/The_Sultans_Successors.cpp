#include <iostream>
#include <vector>
#include <map>

using namespace std;
map<vector<vector<bool>>, pair<int, bool>> mp;

pair<int, bool> dp(vector<vector<int>> &v, vector<vector<bool>> &visit, int ind){
    if(ind == 8){
        return {0, true};
    }

    pair<int, bool> mx = {0, false};
    for(int j = 0; j != 8; j++){
        if(visit[ind][j]){
            vector<vector<bool>> save = visit;
            for(int i = 0; i < 8 && ind+i < 8; i++){
                save[ind+i][j] = false;
            }
            for(int i = 0; i < 8 && ind+i < 8 && j+i < 8; i++){
                save[ind+i][j+i] = false;
            }
            for(int i = 0; i < 8 && ind+i < 8 && j-i > -1; i++){
                save[ind+i][j-i] = false;
            }

            pair<int, bool> p =  dp(v, save, ind+1);
            if(p.second){
                p.first += v[ind][j];
                mx= max(mx, p);
            }
        }
    }

    return mx;
}

int main(){
    int n;
    cin >> n;
    for(int i = 0; i != n; i++){
        mp.clear();
        vector<vector<int>> v(8, vector<int>(8));
        for(int i = 0; i != 8; i++){
            for(int j = 0; j != 8; j++){
                cin >> v[i][j];
            }
        }

        vector<vector<bool>> visit(8, vector<bool> (8, true));
        printf("%5d\n", dp(v, visit, 0).first);
    }
}
