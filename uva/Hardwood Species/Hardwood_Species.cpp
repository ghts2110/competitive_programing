#include <iostream>
#include <map>
#include <string>

using namespace std;

int main(){
    int t;
    cin >> t;

    string s;
    getline(cin, s);
    getline(cin, s);

    bool f = true;
    while(t--){
        if(!f){
            cout << endl;
        }
        f = false;

        map<string, int> mp;
        int cont = 0;
        
        while(getline(cin, s)){
            if(s == ""){
                break;
            }

            cont++;
            mp[s]++;
        }

        for(auto it : mp){
            double d = double(it.second * 100.0) / double(cont);
            cout << it.first;
            printf(" %.4lf\n", d);
        }
    }
}
