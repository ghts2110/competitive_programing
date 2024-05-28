#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main(){
    string s1, s2;
    while(cin >> s1 >> s2){
        map<char, vector<int>> mp;
        for(int i = 0; i != s2.size(); i++){
            mp[s2[i]].push_back(i);    
        }

        int i = 0;
        int j = 0;
        while(true){
            j = lower_bound(mp[s1[i]].begin(), mp[s1[i]].end(), j) - mp[s1[i]].begin();
            if(j == mp[s1[i]].size()){
                break;
            }
            j = mp[s1[i]][j];
            j++;
            i++;

            if(j == s2.size()){
                break;
            }
        }

        if(i == s1.size()){
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }
    }
}
