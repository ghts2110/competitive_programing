#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <string>

using namespace std;

bool validate(int x, int y){
    if(x < 0 || y < 0){
        return false;
    }
    if(x > 7 || y > 7){
        return false;
    }

    return true;
}

int main(){
    map<pair<int, int>, string> mp;
    mp[make_pair(-1, -1)] = "LU";
    mp[make_pair(0, -1)] = "L";
    mp[make_pair(1, -1)] = "LD";
    mp[make_pair(-1, 0)] = "U";
    mp[make_pair(1, 0)] = "D";
    mp[make_pair(-1, 1)] = "RU";
    mp[make_pair(0, 1)] = "R";
    mp[make_pair(1, 1)] = "RD";
    pair<int, int> adj[] = {make_pair(-1, -1), make_pair(0, -1), make_pair(1, -1),
                            make_pair(-1, 0), make_pair(1, 0), make_pair(-1, 1),
                            make_pair(0, 1),make_pair(1, 1)};
    int a, b;
    char c, d;
    cin >> c >> a >> d >> b;

    pair<int, int> s, t;
    s = make_pair(8-a, c-'a');
    t = make_pair(8-b, d-'a');

    vector<vector<int> > visit(8, vector<int> (8, -1));
    visit[s.first][s.second] = 0;
    queue<pair<int, int> > q;
    q.push(s);

    while(!q.empty()){
        pair<int, int> no = q.front();
        q.pop();

        for(auto it : adj){
            int x = no.first + it.first;
            int y = no.second + it.second;

            if(validate(x, y) && visit[x][y] == -1){
                visit[x][y] = visit[no.first][no.second]+1;
                q.push(make_pair(x, y));
            }
        }
    }

    cout << visit[t.first][t.second] << endl;
    int x = t.first, y = t.second;

    vector<string> vs;
    while(visit[x][y] != 0){
        for(auto it : adj){
            if(validate(x+it.first, y+it.second) && visit[x][y] == visit[x+it.first][y+it.second]+1){
                x += it.first;
                y += it.second;

                if(it == make_pair(-1, -1)){
                    vs.push_back("RD");
                }else if(it == make_pair(0, -1)){
                    vs.push_back("R");
                }else if(it == make_pair(1, -1)){
                    vs.push_back("RU");
                }else if(it == make_pair(-1, 0)){
                    vs.push_back("D");
                }else if(it == make_pair(1, 0)){
                    vs.push_back("U");
                }else if(it == make_pair(-1, 1)){
                    vs.push_back("LD");
                }else if(it == make_pair(0, 1)){
                    vs.push_back("L");
                }else{
                    vs.push_back("LU");
                }
            }
        }
    }

    for(int i = vs.size()-1; i != -1; i--){
        cout << vs[i] << endl;
    }
}