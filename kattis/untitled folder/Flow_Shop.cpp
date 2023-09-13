#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main(){
    int n, m;
    while(cin >> n >> m){
        vector<vector<int> > v(n, vector<int> (m));

        for(int i= 0; i != n; i++){
            for(int j = 0; j != m; j++){
                cin >> v[i][j];
            }
        }

        for(int i= 1; i != n; i++){
            v[i][0] += v[i-1][0];
        }

        for(int i= 1; i != m; i++){
            v[0][i] += v[0][i-1];
        }

        for(int i= 1; i != n; i++){
            for(int j= 1; j != m; j++){
                v[i][j] += max(v[i][j-1], v[i-1][j]);
            }
        }

        for(int i = 0; i != n; i++){
            cout << v[i][m-1] << " ";
        }
        cout << endl;
    }
}