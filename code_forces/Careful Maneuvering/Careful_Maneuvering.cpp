#include <iostream>
#include <vector>
#include <map>
#include <math.h>

using namespace std;
typedef long long ll;

ll eixo(pair<ll, ll> p1, pair<ll, ll> p2){
    return round((p1.second - (double(p2.second-p1.second)*double(p1.first)/double(p2.first-p1.first))) * 1000000000);
}

int main(){
    int n, m;
    cin >> n >> m;

    vector<pair<int, ll>> v(n);
    for(int i = 0; i != n; i++){
        int y;
        cin >> y;
        v[i].first = -100;
        v[i].second = y;
    }

    map<ll, vector<ll>> mp;
    for(int i = 0; i != m; i++){
        int x, y;
        x = 100;
        cin >> y;


        for(int j = 0; j != v.size(); j++){
            mp[eixo({x, y}, v[j])].push_back(j+61);
            mp[eixo({x, y}, v[j])].push_back(i);
        }
    }

    vector<vector<int>> v2(mp.size());
    int cont = -1;
    for(auto it : mp){
        cont++;
        for(auto ij : it.second){
            v2[cont].push_back(ij);
        }
    }

    int mx = 0;
    for(int i = 0; i < v2.size(); i++){
        for(int j = i; j < v2.size(); j++){
            map<int, bool> save;
            cont = 0;
            for(auto it : v2[i]){
                if(!save[it]){
                    cont++;
                }
                save[it] = true;
            }

            for(auto it : v2[j]){
                if(!save[it]){
                    cont++;
                }
                save[it] = true;
            }
            
            mx = max(mx, cont);
        }
    }

    cout << mx << endl;
}
