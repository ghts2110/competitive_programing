#include <iostream>
#include <vector>

using namespace std;

void st(vector<vector<pair<int, int> > > &memo, int i , int j){
    if(memo[i][j].first < memo[i-1][j].first){
        memo[i][j] = memo[i-1][j];
    }else if(memo[i][j].first == memo[i-1][j].first && memo[i][j].second > memo[i-1][j].second){
        memo[i][j] = memo[i-1][j];
    }

    if(memo[i][j].first < memo[i][j-1].first){
        memo[i][j] = memo[i][j-1];
    }else if(memo[i][j].first == memo[i][j-1].first && memo[i][j].second > memo[i][j-1].second){
        memo[i][j] = memo[i][j-1];
    }

}

int main(){
    int n;
    cin >> n;

    vector<int> v(n);
    for(int i = 0; i != n ;i++){
        cin >> v[i];
    }

    vector<vector<pair<int, int> > > memo(n+1, vector<pair<int, int> > (n+1));

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(v[j-1] > memo[i-1][j-1].second){
                memo[i][j].second = v[j-1];
                memo[i][j].first = memo[i-1][j-1].first+1;
            }

            st(memo, i, j);
        }
    }

    cout << memo[n][n].first << endl;
}
