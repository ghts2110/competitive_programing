#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    while(cin >> n) {

        vector<vector<int> > v(n, vector<int>(n));
        for (int i = 0; i != n; i++) {
            for (int j = 0; j != n; j++) {
                cin >> v[i][j];
            }
        }

        vector<vector<int> > save(n, vector<int>(n));
        int mx = -1e9;
        for (int p = 0; p != n; p++) {
            for (int q = 0; q != n; q++) {
                for (int i = p; i != n; i++) {
                    for (int j = q; j != n; j++) {
                        save[i][j] = v[i][j];
                        if (i != p) {
                            save[i][j] += save[i - 1][j];
                        }
                    }
                }

                for (int i = p; i != n; i++) {
                    for (int j = q; j != n; j++) {
                        if (j != q) {
                            save[i][j] += save[i][j - 1];
                        }

                        mx = max(mx, save[i][j]);
                    }
                }
            }
        }

        cout << mx << endl;
    }
}