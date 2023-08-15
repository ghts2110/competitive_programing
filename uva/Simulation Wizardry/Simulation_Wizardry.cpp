#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main(){
    int n, m;
    cin >> m >> n;
    int dp, p;
    cin >> dp >> p;

    map<pair<int, int>, pair<int, int>> mp;

    for(int i = 0; i != p; i++){
        int x, y, v, db;
        cin >> x >> y >> v >> db;
        mp[pair<int, int>(x, y)] = pair<int, int>(v, db); 
    }

    int x, y, d, l, value = 0;
    while(cin >> x >> y >> d >> l){
        int cont = 0;
        while(--l > 0){

            if(d == 0){
                auto it = mp.find(make_pair(x+1,y));
                if(x+1 == m){
                    d = 3;
                    l -= dp;
                }else if(it != mp.end()){
                    l -= mp[make_pair(x+1, y)].second;
                    cont += mp[make_pair(x+1,y)].first;
                    d = 3;
                }else{
                    x++;
                }
            }else if(d == 1){
                auto it = mp.find(make_pair(x,y+1));
                if(y+1 == n){
                    d = 0;
                    l -= dp;
                }else if(it != mp.end()){
                    l -= mp[make_pair(x, y+1)].second;
                    cont += mp[make_pair(x,y+1)].first;
                    d = 0;
                }else{
                    y++;
                }
            }else if(d == 2){
                auto it = mp.find(make_pair(x-1,y));
                if(x-1 == 1){
                    d = 1;
                    l -= dp;
                }else if(it != mp.end()){
                    l -= mp[make_pair(x-1, y)].second;
                    cont += mp[make_pair(x-1,y)].first;
                    d = 1;
                }else{
                    x--;
                }
            }else{
                auto it = mp.find(make_pair(x,y-1));
                if(y-1 == 1){
                    d = 2;
                    l -= dp;
                }else if(it != mp.end()){
                    l -= mp[make_pair(x, y-1)].second;
                    cont += mp[make_pair(x,y-1)].first;
                    d = 2;
                }else{
                    y--;
                }
            }
        }    
        cout << cont << endl;
        value += cont;
    }
    cout << value << endl;
}
