#include <iostream>
#include <string>
#include <map>
#include <vector>

#define pb push_back

using namespace std;

int main(){
    int t;
    int cont = 0;
    while(cin >> t){
        if(cont != 0){
            cout << endl;
        }
        cont++;

        map<string, int> mp;
        vector<string> v;
            
        string s;
        for(int i = 0; i !=t; i++){
            cin >> s;
            v.pb(s);
        }
    
        int p, n, r;
        for(int i = 0;i != t;i++){
            cin >> s;
            cin >> p >> n;

            if(n == 0){
                continue;
            }

            mp[s] -= p;
            for(int j = 0; j != n; j++){
                string name;
                cin >> name;
                mp[name] += p/n;
                r = p%n;
            }
            mp[s] += r;

        }

        for(int i = 0; i != t; i++){
            cout << v[i] << " " << mp[v[i]] << endl;
        }

    }
}
