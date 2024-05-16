#include <iostream>
#include <vector>
#include <map>
#include <deque>

using namespace std;

map<int, pair<int, deque<int>>> memo;

pair<int, deque<int>> dp(int ind, vector<pair<int, int>> &v){
    if(memo[ind].first != 0){
        return memo[ind];
    }
    
    pair<int, deque<int>> p;
    for(int i = 0; i != v.size(); i++){
        if(v[ind].first < v[i].first && v[ind].second > v[i].second){
            p = max(p, dp(i, v));
        }
    }
    p.first++;
    p.second.push_front(ind+1);

    return memo[ind] = p;
}

int main(){
    vector<pair<int, int>> v;
    int n, s;
    while(cin >> n >> s){
        if(n == -1){
            break;
        }
        v.push_back({n,s});
    }

    pair<int, deque<int>> asw;
    for(int i = 0; i != v.size(); i++){
        asw = max(asw, dp(i, v));
    }

    cout << asw.first << endl;
    for(auto it : asw.second){
        cout << it << endl;
    }
}
