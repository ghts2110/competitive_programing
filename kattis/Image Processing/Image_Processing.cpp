#include <iostream>
#include <vector>

using namespace std;

int main(){
    int h, w, n, m;
    cin >> h >> w >> n >> m;

    vector<vector<int> > v1(h, vector<int>(w)), v2(n, vector<int>(m));
    for(int i = 0; i != h; i++){
        for(int j = 0; j != w; j++){
            cin >> v1[i][j];
        }
    }

    for(int i = n-1; i != -1; i--){
        for(int j = m-1; j != -1; j--){
            cin >> v2[i][j];
        }
    }

    vector<vector<int> > asw(h-n+1, vector<int>(w-m+1));
    for(int i = 0; i != h-n+1; i++){
        for(int j = 0; j != w-m+1; j++){
            int sum = 0;

            for(int ii = 0; ii != n; ii++){
                for(int jj = 0; jj != m; jj++){
                    sum += v2[ii][jj] * v1[ii + i][jj + j];
                }
            }

            asw[i][j] = sum;
        }
    }

    for(auto it : asw){
        for(int i : it){
            cout << i << " ";
        }
        cout << endl;
    }
    cout << endl;
}