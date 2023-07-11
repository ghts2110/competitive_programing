#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int t, c, num, color;
    char s = 'Y';
    cin  >> t;
    cin >> c;

    vector<vector<int> > g1(c + 1);

    int i;
    for(i = 0; i != t; i++){
        cin >> num;
        cin >> color;

        g1[0].push_back(color);
        g1[color].push_back(num);
    }

    for(i = 1; i != c + 1; i++){
        sort(g1[i].begin(), g1[i].end());
    }

    for(i = 0; i != t - 1; i++){
        int v = g1[g1[0][i]][0];
        g1[g1[0][i]].erase(g1[g1[0][i]].begin());
        if(v > g1[g1[0][i+1]][0]){
            s = 'N';
        }
    }

    cout << s << endl;
}
