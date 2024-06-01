#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main(){
    int n;
    while(cin >> n){
        vector<int> v;
        map<int, pair<bool, int>> mp;
        for(int i = 0; i != n; i++){
            int num;
            cin >> num;

            v.push_back(num);
            mp[num].first = true;
            mp[num].second++;

        }

        int m;
        cin >> m;

        pair<int, pair<int, int>> p = {1e9, {1e9, 1e9}};
        for(auto it : v){
            if(mp[m-it].first && p.first > abs(m-it-it)){
                if(m-it == it && mp[m-it].second == 1){
                    continue;
                }
                p.first = abs(m-it-it);
                p.second = {min(m-it, it), max(m-it, it)};
            }
        }

        cout << "Peter should buy books whose prices are "<<p.second.first<<" and "<<p.second.second<<"." << endl << endl;
    }
}
