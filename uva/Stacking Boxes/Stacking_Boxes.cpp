#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;
deque<int> memo[31];

deque<int> dp(deque<deque<int>> &v, int n, int m, int ind){
    if(memo[ind].size() != 0){
        return memo[ind];
    }

    if(ind == n -1){
        deque<int> dq;
        dq.push_back(v[ind][m]);
        return memo[ind] = dq;
    }
    
    deque<int> asw;
    for(int i = ind+1; i < n; i++){
        bool val = true;
        for(int j = 0; j != m; j++){
            if(v[ind][j] >= v[i][j]){
                val = false;
                break;
            }
        }

        if(val){
            deque<int> save = dp(v, n, m, i);
            if(asw.size() < save.size()){
                asw = save;
            }
        }
    }
    asw.push_front(v[ind][m]);

    return memo[ind] = asw;
}

int main(){
    int n, m;
    while(cin >> n >> m){
        for(int i = 0; i != 31; i++){
            memo[i] = deque<int>(0);
        }

        deque<deque<int>> v(n, deque<int>(m));
        for(int i = 0; i != n; i++){
            for(int j = 0; j != m; j++){
                cin >> v[i][j];
            }
            sort(v[i].begin(), v[i].end());
        }
        for(int i = 0; i != n; i++){
            v[i].push_back(i+1);
        }
        sort(v.begin(), v.end());

        deque<int> asw;
        for(int i = 0; i != n; i++){
            deque<int> save = dp(v, n, m, i);
            if(asw.size() < save.size()){
                asw = save;
            }
        }
    
        cout << asw.size() << endl;
        for(int i = 0; i != asw.size(); i++){
            if(i != 0){
                cout << " ";
            }
            cout << asw[i];
        }
        cout << endl;
    }
}
