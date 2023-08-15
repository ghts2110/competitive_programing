#include <iostream>
#include <vector>
#include <map>

#define pb push_back

using namespace std;

int n;
vector<vector<vector<int>>> comp;

void save(vector<vector<int>> v){
    comp.pb(v);
    vector<vector<int>> sv(n, vector<int> (n));
    for(int i = 0; i != n; i++){
        for(int j = 0; j != n; j++){
            sv[j][n-i-1] = v[i][j];
        }
    }
    comp.pb(sv);
    for(int i = 0; i != n; i++){
        for(int j = 0; j != n; j++){
            sv[n-i-1][n-j-1] = v[i][j];
        }
    }
    comp.pb(sv);
    for(int i = 0; i != n; i++){
        for(int j = 0; j != n; j++){
            sv[n-j-1][i] = v[i][j];
        }
    }
    comp.pb(sv);
}

bool validate(vector<vector<int>> v){
    for(int i = 0; i != comp.size(); i++){
        if(v == comp[i]){
            return true;
        }
    }
    return false;
}

int main(){
    while(cin >> n){
        if(n == 0){
            break;
        } 

        comp.clear();
        vector<vector<int>> v(n, vector<int> (n));
        bool val = false;
        int asw = 0;

        for(int i = 0; i != 2*n; i++){
            int x, y;
            char m;
            cin >> x >> y >> m;

            if(m == '-'){
                v[x-1][y-1] = 0;
            }else{
                v[x-1][y-1] = 1;
            }

            if(val){
                continue;
            }

            if(validate(v)){
                val = true;
                asw = i+1;
            }else{
                save(v);
            }
        }

        if(val){
            if(asw%2 == 0){
                cout << "Player 1";
            }else{
                cout << "Player 2";
            }
            cout << " wins on move "<< asw << endl;
        }else{
            cout << "Draw" << endl;
        }
    }  
}
