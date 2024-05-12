#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    int n;
    string s;
    vector<vector<bool>> v(10, vector<bool>(8));
    v[0][1] = true;
    v[0][2] = true;
    v[0][3] = true;
    v[0][5] = true;
    v[0][6] = true;
    v[0][7] = true;

    v[1][3] = true; 
    v[1][7] = true; 

    v[2][2] = true;
    v[2][3] = true;
    v[2][4] = true;
    v[2][5] = true;
    v[2][6] = true;

    v[3][2] = true;
    v[3][3] = true;
    v[3][4] = true;
    v[3][6] = true;
    v[3][7] = true;

    v[4][1] = true;
    v[4][3] = true;
    v[4][4] = true;
    v[4][7] = true;

    v[5][1] = true;
    v[5][2] = true;
    v[5][4] = true;
    v[5][6] = true;
    v[5][7] = true;

    v[6][1] = true;
    v[6][2] = true;
    v[6][4] = true;
    v[6][5] = true;
    v[6][6] = true;
    v[6][7] = true;

    v[7][2] = true;
    v[7][3] = true;
    v[7][7] = true;

    v[8][1] = true;
    v[8][2] = true;
    v[8][3] = true;
    v[8][4] = true;
    v[8][5] = true;
    v[8][6] = true;
    v[8][7] = true;

    v[9][1] = true;
    v[9][2] = true;
    v[9][3] = true;
    v[9][4] = true;
    v[9][6] = true;
    v[9][7] = true;

    while(cin >> n >> s){
        if(!n){
            break;
        }

        for(int i = 1; i <= 7; i++){
            if(i == 1 || i == 7){
                continue;
            }
            if(i == 2 || i == 4 || i == 6){
                bool f = true;
                for(auto it : s){
                    if(!f){
                        cout << " ";
                    }
                    f = false;

                    cout << " ";
                    for(int j = 0; j != n; j++){
                        if(v[it-'0'][i]){
                            cout << "-";
                        }else{
                            cout << " ";
                        }
                    }
                    cout << " ";
                }
                cout << endl;
            }else if(i == 3){
                for(int k = 0; k != n; k++){
                    bool f = true;
                    for(auto it : s){
                        if(!f){
                            cout << " ";
                        }
                        f = false;

                        if(v[it-'0'][i-2]){
                            cout << "|";
                        }else{
                            cout << " ";
                        }
                        for(int j = 0; j != n; j++){
                            cout << " ";
                        }
                        if(v[it-'0'][i]){
                            cout << "|";
                        }else{
                            cout << " ";
                        }
                    }
                    cout << endl;
                }
            }else{
                for(int k = 0; k != n; k++){
                    bool f = true;
                    for(auto it : s){
                        if(!f){
                            cout << " ";
                        }
                        f = false;

                        if(v[it-'0'][i]){
                            cout << "|";
                        }else{
                            cout << " ";
                        }
                        for(int j = 0; j != n; j++){
                            cout << " ";
                        }
                        if(v[it-'0'][i+2]){
                            cout << "|";
                        }else{
                            cout << " ";
                        }
                    }
                    cout << endl;
                }
            }
        }

        cout << endl;
    }

}
