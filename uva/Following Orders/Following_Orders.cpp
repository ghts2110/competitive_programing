#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>    

using namespace std;
map<pair<char, char>, bool> mp;

void test(string asw, string s, vector<int> &visit){
    if(asw.size() == s.size()){
        cout << asw << endl;
        return;
    }

    for(int i = 0; i != s.size(); i++){
        if(visit[i]){
            continue;
        }
        visit[i] = 1;
    
        bool val = true;
        for(int j = 0; j != s.size(); j++){
            if(visit[j]){
                continue;
            }

            char a = s[j], b = s[i];
            if(mp[{a, b}] == true){
                val = false;
                break;
            }
            
        }
        if(val){
            test(asw+s[i], s, visit);
            
        }
        visit[i] = 0;
    }
}

int main(){
    string s;
    bool f = true;
    while(getline(cin, s)){
        if(s == ""){
            continue;
        }
        if(!f){
            cout << endl;
        }
        f=false;
        

        string save = "";
        for(auto it: s){
            if(it != ' '){
                save += it;
            }
        }
        
        mp.clear();
        getline(cin, s);
        int a = ' ', b = ' ';
        for(auto it : s){
            if(it == ' '){
                if(b != ' '){
                    mp[{a, b}] = true;
                    a = b = ' ';
                }
                continue;
            }

            if(a == ' '){
                a = it;
            }else{
                b = it;
            }
        }
        mp[{a, b}] = true;
        
        sort(save.begin(), save.end());
        vector<int> visit(save.size());
        string asw = "";
        test(asw, save, visit);
    }
}
