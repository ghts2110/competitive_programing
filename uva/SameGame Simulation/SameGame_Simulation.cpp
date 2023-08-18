#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void busca(int x, int y, vector<pair<int, int>>& b, vector<vector<int>>& v, int num){
    b.push_back(make_pair(x, y));
    v[x][y] = -1;
    if(x-1 >= 0 && y < v[x-1].size() && v[x-1][y] == num){
        busca(x-1, y, b, v, num);
    }
    if(x+1 < v.size() && y < v[x+1].size() && v[x+1][y] == num){
        busca(x+1, y, b, v, num);
    }
    if(y-1 >= 0 && v[x][y-1] == num){
        busca(x, y-1, b, v, num);
    }
    if(y+1 < v[x].size() && v[x][y+1] == num){
        busca(x, y+1, b, v, num);
    }
}

bool validate(vector<vector<int>>& v, int x, int y){
    if(x-1 >= 0 && y < v[x-1].size() && v[x-1][y] == v[x][y]){
        return true;
    }
    if(x+1 < v.size() && v[x+1][y] == v[x][y]){
        return true;
    }
    if(y-1 >= 0  && y < v[x+1].size() && v[x][y-1] == v[x][y]){
        return true;
    }
    if(y+1 < v[x].size() && v[x][y+1] == v[x][y]){
        return true;
    }
    return false;
}

int main(){
    int m, n, test = 1;
    while(cin >> m >> n){
        if(m == n && m == 0){
            break;
        }

        vector<vector<int>> v(n, vector<int> (m));
        for(int i = 0; i != m; i++){
            for(int j = 0; j != n; j++){
                cin >> v[j][i];                
            }
        }

        int x,y;
        while(cin >> x >> y){
            if(x == y && x == 0){
                break;
            }
            x--;
            y--;
            
            if(y >= v.size() || x >= v[y].size() || !(validate(v, y, x))){
                continue;
            }

            vector<pair<int, int>> b;
            busca(y, x, b, v, v[y][x]);
            sort(b.begin(), b.end());
            for(int i = b.size()-1; i !=  -1; i--){
                v[b[i].first].erase(v[b[i].first].begin() + b[i].second);
            }
            for(int i = 0; i != v.size(); i++){
                if(v[i].size() == 0){
                    v.erase(v.begin()+i);
                    i--;
                }
            }
        }

        if(test != 1){
            cout << endl;
        }
        cout << "Grid "<<test<<"." << endl;
        test++;

        if(v.size() == 0){
            cout << "    Game Won" << endl;
        }else{
            vector<vector<int>> asw(m, vector<int> (n, -1));

            for(int i = 0; i != v.size(); i++){
                for(int j = 0; j != v[i].size(); j++){
                    asw[j][i] = v[i][j];
                }
            } 

            for(int i = asw.size()-1; i != -1; i--){
                for(int j = 0; j != asw[i].size(); j++){
                    if(j == 0){
                        cout << "    ";
                    }

                    if(asw[i][j] == -1){
                        cout << " ";
                    }else{
                        cout << asw[i][j];
                    }
                    if(j  == asw[i].size()-1){
                        cout << endl;
                        break;
                    }
                    cout << " ";
                }
            }
        }
    }
}
