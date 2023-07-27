#include <iostream>
#include <vector>
#include <cmath>

#define pb push_back

using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        int n, m;
        cin >> n >> m;
        vector<vector<int>> v(n);
        vector<int> prz, stk;
        for(int i = 0; i != n; i++){
            int k;
            cin >> k;

            for(int j = 0; j != k; j++){
                int num;
                cin >> num;

                v[i].pb(num);
            }

            int p;
            cin >> p;

            prz.pb(p);
        }
        
        for(int i = 0; i != m; i++){
            int num;
            cin >> num;

            stk.pb(num);
        }

        int mn, cont = 0;
        for(int i = 0; i != n; i++){
            mn = 1e9;
            for(int j = 0; j != v[i].size(); j++){
                mn = min(mn, stk[v[i][j] - 1]);
            }
            cont += mn * prz[i];
        }

        cout << cont << endl;
    }
}
