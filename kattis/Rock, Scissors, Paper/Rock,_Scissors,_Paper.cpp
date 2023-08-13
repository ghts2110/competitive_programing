#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    int t;
    cin >> t;

    int test = 1;
    while(t--){
        if(test != 1){
            cout << endl;
        }
        test++;

        int r, c, n;
        cin >> r >> c >> n;

        vector<vector<char>> v(r, vector<char> (c));
        for(int i = 0; i != r; i++){
            for(int j = 0; j != c; j++){    
                cin >> v[i][j];
            }
        }

        while(n--){
            vector<vector<char>> save = v;
            for(int i = 0; i != r; i++){
                for(int j = 0; j != c; j++){
                    if(v[i][j] == 'R'){
                        if(i+1 < r && v[i+1][j] == 'S'){
                            save[i+1][j] = 'R';
                        }
                        if(i-1 >= 0 && v[i-1][j] == 'S'){
                            save[i-1][j] = 'R';
                        }
                        if(j+1 < c && v[i][j+1] == 'S'){
                            save[i][j+1] = 'R';
                        }
                        if(j-1 >= 0 && v[i][j-1] == 'S'){
                            save[i][j-1] = 'R';
                        }
                    }else if(v[i][j] == 'S'){
                        if(i+1 < r && v[i+1][j] == 'P'){
                            save[i+1][j] = 'S';
                        }
                        if(i-1 >= 0 && v[i-1][j] == 'P'){
                            save[i-1][j] = 'S';
                        }
                        if(j+1 < c && v[i][j+1] == 'P'){
                            save[i][j+1] = 'S';
                        }
                        if(j-1 >= 0 && v[i][j-1] == 'P'){
                            save[i][j-1] = 'S';
                        }
                    }else if(v[i][j] == 'P'){
                        if(i+1 < r && v[i+1][j] == 'R'){
                            save[i+1][j] = 'P';
                        }
                        if(i-1 >= 0 && v[i-1][j] == 'R'){
                            save[i-1][j] = 'P';
                        }
                        if(j+1 < c && v[i][j+1] == 'R'){
                            save[i][j+1] = 'P';
                        }
                        if(j-1  >= 0 && v[i][j-1] == 'R'){
                            save[i][j-1] = 'P';
                        }
                    }
                }
            }
            v = save;
        }

        for(int i = 0; i != r; i++){
            for(int j = 0; j != c; j++){
                cout << v[i][j];
            }
            cout << endl;
        }

    }
}
