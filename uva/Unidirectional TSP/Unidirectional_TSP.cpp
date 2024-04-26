#include <iostream>
#include <deque>
#include <vector>

using namespace std;
int n, m;
deque<int> memo[101][101];

deque<int> dp(int ind, int line, vector<vector<int>> &v){
    if(ind >= m){
        return deque<int>(1);
    }

    if(memo[ind][line].size() != 0){
        return memo[ind][line];
    }

    int l = line+1;
    if(l >= n){
        l = 0;
    }
    int r = line-1;
    if(r < 0){
        r = n-1;
    }

    deque<int> m1 = dp(ind+1, l, v);
    deque<int> m2 = dp(ind+1, r, v);
    deque<int> m3 = dp(ind+1, line, v);
    deque<int> mn = min(m1, min(m2, m3));
    int sum = mn.front() + v[line][ind];
    mn.pop_front();
    mn.push_front(line+1);
    mn.push_front(sum);
    return memo[ind][line] = mn;
}


int main(){
    while(cin >> n >> m){
        for(int i = 0; i != 101; i++){
            for(int j = 0; j != 101; j++){
                memo[i][j] = deque<int>(0);
            }
        }

        vector<vector<int>> v(n, vector<int>(m));
        for(int i = 0; i != n; i++){
            for(int j = 0; j != m; j++){
                cin >> v[i][j];
            }
        }

        deque<int> asw(1, 1e9);
        for(int i = 0; i != n;i ++){
            deque<int> save = dp(0, i, v);
            if(asw[0] > save[0]){
                asw = save;
            }
        }
    
        bool f = true;
        for(int i = 1; i != asw.size(); i++){
            if(!f){
                cout << " ";
            }
            f = false;
            
            cout << asw[i];
        }
        cout << endl;
        cout << asw[0] << endl;
    }
}
