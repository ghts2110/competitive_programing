#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

#define pb push_back

using namespace std;

int x, y;
int cont = 0;
int busca(vector<vector<char>>& v, int i, int j, char l){
    cont++;
    v[i][j] = '.';
    if(i+1 < x && v[i+1][j] == l){
        busca(v, i+1, j, l); 
    }
    if(j + 1 < y && v[i][j+1] == l){
        busca(v, i, j+1, l);
    }
    if(i-1 >= 0 && v[i-1][j] == l){
        busca(v, i-1, j, l); 
    }
    if(j- 1 >= 0 && v[i][j-1] == l){
        busca(v, i, j-1, l);
    }
    return cont;
}

int main(){
    int test = 1;

    while(cin >> x >> y){
        if(x == 0){
            break;
        }

        vector<vector<char>> v(x, vector<char>(y));
        for(int i = 0; i != x; i++){
            for(int j = 0; j != y; j++){
                cin >> v[i][j];
            }
        }

        vector<pair<int, int>> asw;
        for(int i = 0; i != x; i++){
            for(int j = 0; j != y; j++){
                if(v[i][j] != '.'){
                    char l = v[i][j];
                    cont = 0;
                    int t = busca(v, i, j, l);
    
                    asw.pb(make_pair(t, abs(l-'Z')));
                }
            }
        }

        sort(asw.begin(), asw.end());
        cout << "Problem "<<test<<":" << endl; 
        test++;
        for(int i = asw.size() -1; i != -1; i--){
            cout << char('Z'-asw[i].second)  << " " << asw[i].first << endl;
        }

        
    }
}
