#include <iostream>
#include <map>
#include <string>

using namespace std;

int main(){
    int k, m;
    while(cin >> k >> m){
        if(k == 0){
            break;
        }

        map<string, bool> mp;
    
        for(int i = 0; i != k; i++){
            string s;
            cin >> s;

            mp[s] = true;
        }

        bool validate = true;
        for(int i = 0; i != m; i++){
            int c, r;
            cin >> c >> r;

            int cont = 0;
            for(int j = 0; j != c; j++){
                string s;
                cin >> s;

                if(mp[s]){
                    cont++;
                }
            }

            if(cont < r){
                validate = false;
            }
        }

        if(validate){
            cout << "yes" << endl;
        }else{
            cout << "no" << endl;
        }
    }
}
