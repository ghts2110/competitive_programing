#include <iostream>
#include <map>

using namespace std;

int a, b, c;
int cont;
map<int, int> mp;

void loop(int pote1, int pote2, int v1, int v2){
    if(pote1 == v1 && pote2 == v2){
        return;
    }

    if(mp[pote1] == 0){
        mp[pote1] = cont;
    }else{
        mp[pote1] = min(mp[pote1], cont);
    }

    if(mp[pote2] == 0){
        mp[pote2] = cont;
    }else{
        mp[pote2] = min(mp[pote2], cont);
    }

    cont++;

    if(pote1 == 0){
        loop(v1, pote2, v1, v2);
        return;
    }

    if(pote2 == v2){
        loop(pote1, 0, v1, v2);
        return;
    }

    int mn = min(pote1, v2-pote2);
    loop(pote1-mn, pote2+mn, v1, v2);
}

int main(){
    int t;
    cin >> t;

    while(t--){
        cin >> a >> b >> c;
        mp.clear();

        cont = 1;
        loop(0, 0, a, b);
        
        cont = 1;
        loop(0, 0, b, a);

        cout << mp[c] -1 << endl;
    }
}
