#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    string s;
    map<string, bool> mp;
    while(cin >> s){
        if(s == "::"){
            break;
        }
        mp[s] = true;
    }

    getline(cin, s);
    vector<pair<string, pair<int, string>>> v;
    int cont = 0;
    while(getline(cin, s)){
        if(s == ""){
            break;
        }
        cont++;
        for(auto &it: s){
            it = tolower(it);
        }

        string lower = "";
        int i = 0, j = 0;
        for(int k = 0; k <= s.size(); k++){
            if(s[k] == ' ' || k == s.size()){
                if(k == s.size()){
                    j--;
                }

                if(!mp[lower] && lower != ""){
                    string upper = "";
                    for(int save = i;save<=j;save++){
                        s[save] = toupper(s[save]);
                        if(s[save] != ' '){
                            upper += s[save];
                        }
                    }
                    v.push_back({upper, {cont, s}});
                    for(int save = i;save<=j;save++){
                        s[save] = tolower(s[save]);
                    }
                }
                lower = "";
                i = j =k+1;
            }else if(s[k] != ' '){
                j++;
                lower += tolower(s[k]);
            }
        }
    }
    sort(v.begin(), v.end());
    
    for(auto it : v){
        cout << it.second.second << endl;
    }
}
