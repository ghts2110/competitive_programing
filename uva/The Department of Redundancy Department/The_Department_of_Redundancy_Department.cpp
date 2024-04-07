#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main(){
    int n;
    map<int, int> mp, visit;
    vector<int> v;

    while(cin >> n){
        mp[n]++;
        if(visit[n]){
            continue;
        }
        v.push_back(n);
        visit[n] = true;
    }

    for(auto it : v){
        cout << it << " " << mp[it] << endl;
    }
}
