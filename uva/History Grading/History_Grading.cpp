#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int memo[22];

int dp(int ind, vector<int> v){
    if(ind == v.size()){
        return 1;
    }

    if(memo[ind] != -1){
        return memo[ind];
    }

    int mx = 1;
    for(int i = ind +1; i != v.size(); i++){
        if(v[i] > v[ind]){
            mx = max(mx, dp(i, v)+1);
        }
    }
    return memo[ind] = mx; 
}

int main(){
    string s;
    vector<int> asw, v;
    map<int, int> mp;
    bool f= true;
    while(getline(cin, s)){

        if(s.size() <= 2){
            f = true;
            asw = v = vector<int> (stoi(s)+1);
            mp.clear();
            continue;
        }

        int val = 0;
        if(f){
            string save = "";
            int cont = 1;
            for(int i = 0; i != s.size(); i++){
                if(s[i] != ' '){
                    save += s[i];
                }

                if(s[i] == ' ' || i == s.size()-1){
                    int num = stoi(save);
                    mp[cont] = num;
                    asw[num] = cont;
                    cont++;
                    save = "";
                }
            }
            f=false;
        }else{
            for(auto &it : memo){
                it = -1;
            }

            string save = "";
            int cont = 1;
            for(int i = 0; i != s.size(); i++){
                if(s[i] != ' '){
                    save += s[i];
                }

                if(s[i] == ' ' || i == s.size()-1){
                    int num = stoi(save);
                    save = "";
                    v[num] = mp[cont];
                    cont++;
                }
            }

            for(int i = 1; i <= v.size(); i++){
                val = max(val, dp(i, v)); 
            }
        
            cout << val << endl;
        }

    }
}
