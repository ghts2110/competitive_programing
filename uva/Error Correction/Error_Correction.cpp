#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    while(cin >> n){
        if(!n){
            break;
        }

        vector<vector<int>> v(n, vector<int>(n));
        vector<int> row(n), col(n);
        for(int i = 0; i != n; i++){
            for(int j = 0; j != n; j++){
                cin >> v[i][j];
                row[i] += v[i][j];
                col[j] += v[i][j];
            }
        }

        int contr = 0, contc = 0;
        int r, c;
        for(int i = 0; i != n; i++){
            if(row[i] % 2 == 1){
                r = i;
                contr++;
            }
            if(col[i] % 2 == 1){
                c = i;
                contc++;
            }
        }

        if(contr >= 2 || contc >= 2 || (contr == 1 && contc != 1) || (contr != 1 && contc == 1)){
            cout << "Corrupt" << endl;
            continue;
        }

        if(contr == 0 && contc == 0){
            cout << "OK" << endl;
            continue;
        }

        cout << "Change bit ("<<r+1<<","<<c+1<<")" << endl;
    }
}
