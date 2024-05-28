#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main(){
    string s1, s2;

    while(getline(cin, s1)){
        getline(cin, s2);
        map<char, int> mp;
        for(auto it : s1){
            mp[it]++;
        }

        vector<char> v;
        for(auto it : s2){
            if(mp[it] != 0){
                v.push_back(it);
                mp[it]--;
            }
        }
        sort(v.begin(), v.end());
        for(auto it : v){
            cout << it;
        }
        cout << endl;
    }
}
