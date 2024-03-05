#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <math.h>

using namespace std;
typedef long long ll;

int main(){
    ll n;
    cin >> n;

    vector<pair<ll, ll>> v(n);
    for(int i = 0; i != n ;i++){
        cin >> v[i].first >> v[i].second;
    }

    map<ll, set<pair<ll, ll>>> mp;
    for(int i = 0; i != n-1; i++){
        for(int j = i+1; j != n; j++){
            if(v[i].second == v[j].second){
                continue;
            }

            ll x = round((v[i].first - v[i].second*double(v[j].first-v[i].first)/double(v[j].second-v[i].second)) * 1000000000);
            mp[x].insert({v[i].first, v[i].second});
        }
    }

    map<ll, bool> mp2;
    ll asw = 1;
    for(auto it : mp){
        if(!mp2[it.second.size()]){
            mp2[it.second.size()]=true;
            asw++;
        }
    }

    cout << asw << endl;
}
