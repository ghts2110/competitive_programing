#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
int n;

long long memo[1000][1000];

long long dp(int x, int y, vector<vector<char> > &v){
    if(x == y && x == n-1){
        return 1;
    }

    if(memo[y][x] != -1){
        return memo[y][x];
    }

    long long cont = 0;
    if(y != n-1 && v[y+1][x] != '*'){
        cont = (cont + dp(x, y+1, v)) % 1000000007;
    }
    if(x != n-1 && v[y][x+1] != '*'){
        cont = (cont + dp(x+1, y, v)) % 1000000007;
    }

    return memo[y][x] = cont;
}

int main(){
    cin >> n;

    memset(memo, -1, sizeof(memo));

    vector<vector<char> > v(n, vector<char> (n));
    for(int i = 0; i != n ;i++){
        for(int j = 0; j != n; j++){
            cin >> v[i][j];
        }
    }

    if(v[0][0] == '*'){
        cout << 0 << endl;
    }else{
        cout << dp(0, 0, v) << endl;
    }
}