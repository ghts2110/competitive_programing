#include <iostream>
#include <vector>
#include <string>

using namespace std;

char c[] = {'B', 'G', 'C'};

pair<int, string> dp(int ind, int bt, vector<vector<int>> &v){
    if(ind == 3){
        return {0, ""};
    }

    pair<int, string> mn = {1e9, "ZZZ"};
    for(int i = 0; i != 3; i++){
        pair<int, string> sum;
        if((1<<i) & bt){
            continue;
        }

        sum = dp(ind+1, bt|(1<<i), v);
        sum.second = c[i] + sum.second; 
        for(int j = 0; j != 3; j++){
            if(j == i){
                continue;
            }    
            sum.first += v[ind][j];
        }

        mn = min(mn, sum);
    }

    return mn;
}
int main(){
    int b1, g1, c1, b2, g2, c2, b3, g3, c3;
    while(cin >> b1 >> g1 >> c1 >> b2 >> g2 >> c2 >> b3 >> g3 >> c3){
        vector<vector<int>> v(3, vector<int>(3));
        v[0][0] = b1;
        v[0][1] = g1;
        v[0][2] = c1;
        v[1][0] = b2;
        v[1][1] = g2;
        v[1][2] = c2;
        v[2][0] = b3;
        v[2][1] = g3;
        v[2][2] = c3;
        pair<int, string> asw = dp(0, 0, v);
        cout << asw.second << " " << asw.first << endl;
    }
}
