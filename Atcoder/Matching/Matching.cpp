#include <iostream>
#include <bitset>
#include <cstring>
#include <vector>

using namespace std;

long long memo[(1<<21)];

int main(){
    int n;
    cin >> n;

    vector<vector<int> > v(n, vector<int> (n));

    memset(memo, 0, sizeof memo);

    for(int i = 0; i != n; i++){
        for(int j = 0; j != n;j++){
            cin >> v[i][j];
        }
    }

    memo[0] = 1;
    for(int i = 0; i != (1<<n); i++){
        bitset<21> bt(i);

        int x = 0;
        for(int j = 0; j != n; j++){
            x += bt[j];
        }

        for(int j = 0; j != n; j++){
            if(!bt[j] && v[x][j] && memo[bt.to_ulong()]){
                memo[bt.to_ulong()|(1<<j)]+=memo[bt.to_ulong()];
                memo[bt.to_ulong()|(1<<j)] %= 1000000007;
            }
        }
    }

    cout << memo[(1<<n)-1] << endl;
}