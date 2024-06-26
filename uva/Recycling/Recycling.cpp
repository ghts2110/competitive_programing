#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    string s;
    vector<string> v;

    while(cin >> s){
        if(s == "#"){
            break;
        }

        if(s[0] == 'e'){
            vector<int> asw(v.size());
            for(int i = 0; i != v.size(); i++){
                for(int j = 0; j < v.size(); j++){
                    if(i == j){
                        continue;
                    }
                    if(v[i][0]==v[j][0]){
                        asw[i]++;
                    }
                    if(v[i][1]==v[j][1]){
                        asw[i]++;
                    }
                    if(v[i][2]==v[j][2]){
                        asw[i]++;
                    }
                    if(v[i][3]==v[j][3]){
                        asw[i]++;
                    }
                    if(v[i][4]==v[j][4]){
                        asw[i]++;
                    }
                }
            }

            pair<int, int> mx = {0, 0};
            for(int i = 0; i != asw.size(); i++){
                if(asw[i] > mx.first){
                    mx = {asw[i], i};
                }
            }
            cout << mx.second+1 << endl;

            v.clear();
            continue;
        }

        
        vector<pair<char, char>> save;
        for(int i = 0; i < s.size(); i+=4){
            save.push_back({s[i], s[i+2]});
        }
        sort(save.begin(), save.end());

        s = "";
        for(auto it : save){
            s += it.second;
        }
        v.push_back(s);
    }
}
