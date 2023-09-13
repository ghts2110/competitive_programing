#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<vector<int> > v(4, vector<int>(4));
    for(int i = 0;i != 4; i++){
        for(int j = 0; j != 4; j++){
            cin >> v[i][j];
        }
    }

    int n;
    cin >> n;

    if(n == 0){
        for(int i = 0;i != 4; i++){
            vector<bool> val(4, true);

            for(int j = 1; j != 4; j++){
                int save = v[i][j];
                v[i][j] = 0;
                for(int k = j; k != -1; k--){
                    if(k == 0 && v[i][k] == 0){
                        v[i][k] = save;
                        break;
                    }
                    if(v[i][k] == save && val[k]){
                        v[i][k] += save;
                        val[k] = false;
                        break;
                    }

                    if(v[i][k] != 0){
                        v[i][k+1] += save;
                        break;
                    }
                }
            }
        }
    }else if(n == 2){
        for(int i = 0;i != 4; i++){
            vector<bool> val(4, true);

            for(int j = 2; j != -1; j--){
                int save = v[i][j];
                v[i][j] = 0;
                for(int k = j; k != 4; k++){
                    if(k == 3 && v[i][k] == 0){
                        v[i][k] = save;
                        break;
                    }
                    if(v[i][k] == save && val[k]){
                        v[i][k] += save;
                        val[k] = false;
                        break;
                    }

                    if(v[i][k] != 0){
                        v[i][k-1] += save;
                        break;
                    }
                }
            }
        }
    }else if(n == 1) {
        for (int j = 0; j != 4; j++) {
            vector<bool> val(4, true);

            for (int i = 1; i != 4; i++) {
                int save = v[i][j];
                v[i][j] = 0;

                for (int k = i; k != -1; k--) {
                    if (k == 0 && v[k][j] == 0) {
                        v[k][j] = save;
                        break;
                    }
                    if (v[k][j] == save && val[k]) {
                        v[k][j] += save;
                        val[k] = false;
                        break;
                    }

                    if (v[k][j] != 0) {
                        v[k + 1][j] += save;
                        break;
                    }
                }
            }
        }
    }else{
        for (int j = 0; j != 4; j++) {
            vector<bool> val(4, true);

            for (int i = 2; i != -1; i--) {
                int save = v[i][j];
                v[i][j] = 0;

                for (int k = i; k != 4; k++) {
                    if (k == 3 && v[k][j] == 0) {
                        v[k][j] = save;
                        break;
                    }
                    if (v[k][j] == save && val[k]) {
                        v[k][j] += save;
                        val[k] = false;
                        break;
                    }

                    if (v[k][j] != 0) {
                        v[k - 1][j] += save;
                        break;
                    }
                }
            }
        }
    }

    for(auto & i : v){
        for(int j = 0; j != i.size(); j++){
            if(j == i.size()-1){
                cout << i[j] << endl;
                break;
            }
            cout << i[j] << " ";
        }
    }
}
