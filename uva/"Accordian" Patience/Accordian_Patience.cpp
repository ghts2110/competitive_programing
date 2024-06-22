#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool comp(string s1, string s2){
    return s1[0] == s2[0] || s1[1] == s2[1];
}

int main(){
    string s;
    while(cin >> s){
        if(s == "#"){
            break;
        }
        vector<vector<string>> v(52);
        v[0].push_back(s);
        for(int i = 0; i != 51; i++){
            cin >> s;
            v[i+1].push_back(s);
        }

        int ind = 0;
        while(ind != v.size()){
            if(ind-3 > -1 && comp(*(v[ind].end()-1), *(v[ind-3].end()-1))){
                string save = *(v[ind].end()-1);
                v[ind-3].push_back(save);
                v[ind].erase(v[ind].end()-1);

                if(v[ind].size() == 0){
                    v.erase(v.begin()+ind);
                }
                ind -= 4;
                continue;
            } 
            if(ind-1 > -1 && comp(*(v[ind].end()-1), *(v[ind-1].end()-1))){
                string save = *(v[ind].end()-1);
                v[ind-1].push_back(save);
                v[ind].erase(v[ind].end()-1);

                if(v[ind].size() == 0){
                    v.erase(v.begin()+ind);
                }
                ind -= 2;
                continue;
            }

            ind++;
        }

        int sz = v.size();
        if(sz == 1){
            cout << v.size() << " pile remaining:";
        }else{
            cout << v.size() << " piles remaining:";
        }
        for(auto it : v){
            cout << " " << it.size();
        }
        cout << endl;
    }
}
