#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;

    vector<vector<int> > v(n);

    for(int i = 0; i != n; i++){
        v[i].push_back(0);
        v[i].push_back(i+1);
    }

    for(int i = 0; i != m; i++){
        int ouro, prata, bronze;
        cin >> ouro >> prata >> bronze;

        v[ouro-1][0] += 1000000;
        v[prata-1][0] += 1000;
        v[bronze-1][0] += 1;
    }

    for(int i = 0; i != n-1; i++){
        for(int j = i+1; j != n; j++){
            if((v[i][0] < v[j][0]) || (v[i][0] == v[j][0] && v[i][1] > v[j][1])){
                int save = v[i][0];
                v[i][0] = v[j][0];
                v[j][0] = save;

                save = v[i][1];
                v[i][1] = v[j][1];
                v[j][1] = save;
            }
        }
    }

    for(int i = 0; i != n; i++){
        if(i == n-1){
            cout << v[i][1] << endl;
            return 0;
        }
        cout << v[i][1] << " ";
    }
}
