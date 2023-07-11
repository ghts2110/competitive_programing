#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int cont;
vector<vector<int> > mat;

int main(){
    int t, max_tax;
    cin >> t >> max_tax;
    vector<int> tax;
    vector<vector<int> > path(t-1);

    for(int i = 0; i != t; i++){
        int t;
        cin >> t;

        tax.push_back(t);
    }

    for(int i = 0; i != t - 1; i++){
        int a, b, c;
        cin >> a >> b >> c;

        path[i].push_back(min(a, b));
        path[i].push_back(max(a, b));
        path[i].push_back(c);

    }

    sort(path.begin(), path.end());

    cout << endl;
    for(int i = 0; i != t-1; i++){
        for(int j = 0; j != 3; j++){
            cout << path[i][j] << " ";
        }
        cout << endl;
    }
}
