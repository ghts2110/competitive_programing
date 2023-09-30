#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int t;
    cin >> t;
    map<char, int> mp;
    string s;
    getline(cin, s);

    while(t--){
        getline(cin, s);
        for(int i = 0; i != s.size(); i++){
            if(isalpha(s[i])){
                mp[toupper(s[i])]++;
            }
        }
    }

    vector<pair<int, int> > v;
    for(auto it : mp){
        v.push_back(make_pair(it.second, 'Z'-it.first));
    }

    sort(v.begin(), v.end());
    for(int i = v.size()-1; i != -1; i--){
        cout << char('Z'-v[i].second) << " " << v[i].first << endl;
    }
}