#include <iostream>
#include <vector>

using namespace std; 
int n, m;

void validate(int x, int y, vector<vector<vector<int>>> &v, vector<int> &asw){
    for(int i = 1; i <= n; i++){
        bool val = true;
        for(int j = 0; j != i; j++){
            if(y+j >= n){
                break;
            }

            if((v[x][y+j].size() > 0 && v[x][y+j][0] == 0) || (v[x][y+j].size() > 1 && v[x][y+j][1] == 0)){
            }else{
                val = false;
                break;
            }

            if((v[x+j][y].size() > 0 && v[x+j][y][0] == 1) || (v[x+j][y].size() > 1 && v[x+j][y][1] == 1)){
            }else{
                val = false;
                break;
            }
        }
        for(int j = 0; j != i && val; j++){
            if(x+j >= n){
                break;
            }

            if((v[x+j][y+i].size() > 0 && v[x+j][y+i][0] == 1) || (v[x+j][y+i].size() > 1 && v[x+j][y+i][1] == 1)){
            }else{
                val = false;
                break;
            }

            if((v[x+i][y+j].size() > 0 && v[x+i][y+j][0] == 0) || (v[x+i][y+j].size() > 1 && v[x+i][y+j][1] == 0)){
            }else{
                val = false;
                break;
            }
        }

        if(val){
            asw[i]++;
        }
    }
}

int main(){
    int test = 1;
    while(cin >> n >> m){
        if(test != 1){
            cout << endl << "**********************************" << endl << endl;
        }

        vector<vector<vector<int>>> v(n, vector<vector<int>> (n));
        while(m--){
            char c;
            int a, b;
            cin >> c >> a >> b;
            a--;
            b--;
            if(c == 'H'){
                v[a][b].push_back(0);
            }else{
                v[b][a].push_back(1);
            }
        }

        vector<int> asw(n);
        for(int i = 0; i != n; i ++){
            for(int j = 0; j != n; j++){
                validate(i, j, v, asw);
            }
        }

        cout << "Problem #" << test << endl << endl;
        test++;
        bool val = true;
        for(auto it : asw){
            if( it != 0 ){
                val = false;
                break;
            }
        }

        if(val){
            cout << "No completed squares can be found." << endl;
        }else{
            for(int i = 0; i != n ; i++){
                if(asw[i] != 0){
                    cout << asw[i] << " square (s) of size "<< i << endl;
                }
            }
        }

    }
}
