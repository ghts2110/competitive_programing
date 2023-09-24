#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool validate(pair<int, int> q, pair<int,int> adj, vector<vector<bool> > &visit){
    q.first += adj.first;
    q.second += adj.second;

    if(q.first < 0 || q.first >= 8){
        return false;
    }
    if(q.second < 0 || q.second >= 8){
        return false;
    }

    if(visit[q.first][q.second]){
        visit[q.first][q.second] = false;
        return true;
    }

    return false;
}

int main(){
    int t;
    cin >> t;

    while(t--){
        int x, y;
        char a, b;

        cin >> a >> x >> b >> y;

        pair<int,int> adj[] = {make_pair(-2, 1), make_pair(-2, -1), make_pair(-1, -2),
                               make_pair(-1, 2), make_pair(2, 1), make_pair(2, -1),
                               make_pair(1, -2),make_pair(1, 2) };

        vector<vector<int> > v(8, vector<int> (8)), asw(8, vector<int> (8));
        vector<vector<bool> > visit(8, vector<bool>(8, true));
        pair<int, int> start = make_pair(abs(8-x), a-'a'), finish = make_pair(abs(8-y), b-'a');

        visit[start.first][start.second] = false;
        queue<pair<int, int> > q;
        q.push(start);

        while(!q.empty()){
            if(q.front() == finish){
                cout << asw[q.front().first][q.front().second] << endl;
                break;
            }

            for(auto it : adj){
                if(validate(q.front(), it, visit)){
                    asw[q.front().first+it.first][q.front().second+it.second] = asw[q.front().first][q.front().second]+1;
                    q.push(make_pair(q.front().first+it.first, q.front().second+it.second));
                }
            }

            q.pop();
        }
    }
}