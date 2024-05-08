#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

map<int, bool> mp;
int n;

void dp(int ind, vector<int> &v, int cont, string s){
    if(ind != 1){
        s += ' ';
    }
    s += to_string(ind);
    if(cont == n && mp[ind+1]){
        cout << s << endl;
        return;
    }else if(cont == n){
        return;
    }
    
    v[ind] = 1;
    
    for(int i = 1; i != v.size(); i++){
        if(v[i] == 0 && mp[i+ind]){
            dp(i, v, cont+1, s);
        } 
    }
    v[ind] = 0;
}

int main(){
    mp[2] = true;
    mp[3] = true;
    mp[5] = true;
    mp[7] = true;
    mp[11] = true;
    mp[13] = true;
    mp[17] = true;
    mp[19] = true;
    mp[23] = true;
    mp[29] = true;
    mp[31] = true;
    int test = 1;
    while(cin >> n){
        if(test != 1){
            cout << endl;
        }
        cout << "Case "<<test<<":" << endl;
        test++;
    
        vector<int> v(n+1);
        string s;
        dp(1, v, 1, s);
    }
}
