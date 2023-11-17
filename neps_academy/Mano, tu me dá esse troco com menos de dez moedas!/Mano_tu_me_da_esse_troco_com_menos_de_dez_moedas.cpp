#include <iostream>
#include <vector>
#include <map>

using namespace std;
int n, m;

map<int, map<int, bool> > mp;

bool dp(int ind, int cont, vector<int> &v){
    if(ind == 10){
        return false;
    }

    if(cont == m){
        return true;
    }

    if(mp[ind].find(cont) != mp[ind].end()){
        return mp[ind][cont];
    }

    bool asw = false;
    for(int i = 0; i != n; i++){
        if(cont+v[i] <= m){
            if(dp(ind+1, cont+v[i], v)){
                asw = true;
            }
        }
    }

    return mp[ind][cont] = asw;
}
int main(){
    cin >> n >> m;

    vector<int> v(n);
    for(int i =0; i != n; i++){
        cin >> v[i];
    }

    if(dp(0, 0, v)){
        cout << "S" << endl;
    }else{
        cout << "N" << endl;
    }
}