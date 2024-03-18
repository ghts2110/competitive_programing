#include <iostream>
#include <string>
#include <map>

using namespace std;
map<pair<int, int>, bool> mp;
map<char, char> l, r;

void run(pair<pair<int, int>, char> &p, char c){
    if(c == 'R'){
        p.second = r[p.second];
        return;
    }
    if(c == 'L'){
        p.second = l[p.second];
        return;
    }

    if(p.second == 'N'){
        p.first.second++;
    }else if(p.second == 'S'){
        p.first.second--;
    }else if(p.second == 'E'){
        p.first.first++;
    }else{
        p.first.first--;
    }
}

int main(){
    l['E'] = 'N';
    l['W'] = 'S';
    l['N'] = 'W';
    l['S'] = 'E';

    r['E'] = 'S';
    r['W'] = 'N';
    r['N'] = 'E';
    r['S'] = 'W';

    int a, b;
    cin >> a >> b;

    int sx, sy;
    char c;
    while(cin >> sx >> sy >> c){
        string s;
        cin >> s;

        pair<pair<int, int>, char> p = {{sx, sy}, c};
        bool val = true;
        for(auto it : s){
            run(p, it);

            int x = p.first.first;
            int y = p.first.second;

            if(x > a || y > b || x < 0 || y < 0){
                if(x > a){
                    p.first.first--;
                }else if(y > b){
                    p.first.second--;
                }else if(x < 0){
                    p.first.first++;
                }else{
                    p.first.second++;
                }

                if(mp[p.first]){
                    continue;
                }   


                mp[p.first] = true;

                val = false;
                break;
            }
        } 

        cout << p.first.first << " " << p.first.second << " " << p.second;
        if(val){
            cout << endl;
        }else{
            cout << " LOST" << endl;
        }
    }
}
