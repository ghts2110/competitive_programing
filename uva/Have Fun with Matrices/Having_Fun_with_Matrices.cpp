#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    int t;
    cin >> t;

    for(int test = 1; test <= t; test++){
        int n;
        cin >> n;

        vector<vector<char> > v(n, vector<char> (n));

        for(int i = 0; i != n; i++){
            for(int j = 0; j != n; j++){
                cin >> v[i][j];
            }
        }

        int m;
        cin >> m;

        for(int i = 0; i != m; i++){
            string s;
            cin >> s;

            if(s == "row"){
                int a, b;
                cin >> a >> b;
                a--;
                b--;

                vector<char> save = v[a];
                v[a] = v[b];
                v[b] = save;
            }else if(s == "col"){
                int a, b;
                cin >> a >> b;
                a--;
                b--;

                for(int j = 0; j != n; j++){
                    char save = v[j][a];
                    v[j][a] = v[j][b];
                    v[j][b] = save;
                }
            }else if(s == "inc"){
                for(int j = 0; j != n; j++){
                    for(int k = 0; k != n; k++){
                        if(v[j][k] == '9'){
                            v[j][k] = '0';
                        }else{
                            v[j][k]++;
                        }
                    }
                }
            }else if(s == "dec"){
                for(int j = 0; j != n; j++){
                    for(int k = 0; k != n; k++){
                        if(v[j][k] == '0'){
                            v[j][k] = '9';
                        }else{
                            v[j][k]--;
                        }
                    }
                }
            }else{
                vector<vector<char> > save = v;
                for(int j = 0; j != n; j++){
                    for(int k = 0; k != n; k++){
                        v[j][k] = save[k][j];
                    }
                }
            }
        }

        cout << "Case #"<<test << endl;
        for(auto i : v){
            for(char j : i){
                cout << j;
            }
            cout << endl;
        }

        cout << endl;
    }
}