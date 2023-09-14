#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int n, test = 0;

vector<vector<char> > deg(vector<vector<char> > &v){
    vector<vector<char> > save(n, vector<char>(n));

    for(int i = 0; i != n; i++){
        for(int j = 0; j != n; j++){
            save[j][n-1-i] = v[i][j];
        }
    }

    return save;
}

vector<vector<char> > ref(vector<vector<char> > &v){
    vector<vector<char> > save(n, vector<char>(n));

    for(int i = 0; i != n; i++){
        for(int j = 0; j != n; j++){
            save[n-i-1][j] = v[i][j];
        }
    }

    return save;
}

int main(){
    while(cin >> n){
        test++;

        vector<vector<char> > v(n, vector<char>(n)), m(n, vector<char>(n));
        for(int i = 0;i != n; i++){
            for(int j = 0; j != n; j++){
                cin >> v[i][j];
            }

            for(int j = 0; j != n; j++){
                cin >> m[i][j];
            }
        }

        cout << "Pattern " << test << " was ";
        if(v == m){
            cout << "preserved." << endl;
            continue;
        }

        vector<vector<char> > save = deg(v);
        if(save == m){
            cout << "rotated 90 degrees." << endl;
            continue;
        }

        save = deg(save);
        if(save == m){
            cout << "rotated 180 degrees." << endl;
            continue;
        }

        save = deg(save);
        if(save == m){
            cout << "rotated 270 degrees." << endl;
            continue;
        }

        save = ref(v);
        if(save == m){
            cout << "reflected vertically." << endl;
            continue;
        }

        save = deg(save);
        if(save == m){
            cout << "reflected vertically and rotated 90 degrees." << endl;
            continue;
        }

        save = deg(save);
        if(save == m){
            cout << "reflected vertically and rotated 180 degrees." << endl;
            continue;
        }

        save = deg(save);
        if(save == m){
            cout << "reflected vertically and rotated 270 degrees." << endl;
            continue;
        }

        cout << "improperly transformed." << endl;
    }
}