#include <iostream>
#include <vector>
#include <string>
typedef long long ll;
using namespace std;

int main(){
    ll t;
    cin >> t;

    int cont = 0;
    string s;
    while(t--){

        if(cont != 0){
            cout << endl;
        }

        cont = 1;

        getline(cin,s);
        getline(cin,s);
        getline(cin,s);

        vector<ll>ind;
        string aux = "";
        ll mx = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] != ' '){
                aux+= s[i];
            }

            if(s[i] == ' '  || i == s.size()-1){
                ind.push_back(stoi(aux)-1);

                if(mx < stoi(aux)){
                    mx = stoi(aux);
                }

                aux = "";
                continue;
            }



        }

        vector<string>v(mx);
        for(int i = 0; i < ind.size(); i++){
            cin >> s;
            v[ind[i]] = s;           
        }

        for(int i = 0; i < mx; i++){
            cout << v[i] << endl;
        }
    }

}
