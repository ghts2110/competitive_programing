#include <iostream>
#include <vector>

using namespace std;

int main(){
    int t;
    cin >> t;

    int test = 1;
    while(t--){
        int n;
        cin >> n;

        if(test != 1){
            cout << endl;
        }
        test++;

        vector<vector<char>> v(n, vector<char> (n));
        for(int i = 0; i != n; i++){
            for(int j = 0; j != n; j++){
                cin >> v[i][j];
            }
        }

        vector<vector<char>> asw(n, vector<char> (n));
        bool validate = false;

        for(int i = 0; i != n; i++){
            for(int j = 0; j != n; j++){
                char c;
                cin >> c;

                if(c == 'x' && v[i][j] == '*'){
                    validate = true;
                }

                if(c == 'x'){
                    int cont = 0;
                    if(i+1 < n && v[i+1][j] == '*'){
                        cont++;
                    }
                    if(i+1 < n && j-1 > -1 && v[i+1][j-1] == '*'){
                        cont++;
                    }
                    if(j-1 > -1 && v[i][j-1] == '*'){
                        cont++;
                    }
                    if(j-1 > -1 && i-1 > -1 && v[i-1][j-1] == '*'){
                        cont++;
                    }
                    if(i-1 > -1 && v[i-1][j] == '*'){
                        cont++;
                    }
                    if(i-1 > -1 && j+1 < n && v[i-1][j+1] == '*'){
                        cont++;
                    }
                    if(j+1 < n && v[i][j+1] == '*'){
                        cont++;
                    }
                    if(i+1 < n && j+1 < n && v[i+1][j+1] == '*'){
                        cont++;
                    }

                    asw[i][j] = cont + '0';
                }else{
                    asw[i][j] = '.';
                }
            }
        }

        if(validate){
            for(int i = 0; i != n; i++){
                for(int j = 0; j != n; j++){
                    if(v[i][j] == '*'){
                        asw[i][j] = '*';
                    }
                }    
            }
        }

        for(int i = 0; i != n; i++){
            for(int j = 0; j != n; j++){
                cout << asw[i][j];
            }    
            cout << endl;
        }

    }
}
