#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;

        string s;
        cin >> s;

        if(n % 2 == 1){
            cout << -1 << endl;
            continue;
        }

        bool val = false;
        int cont = 0;
        vector<int> v;

        int p = s.size()-1;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == s[p]){
                cont++;
                if(cont == 301){
                    break;
                }

                if(s[i] == '1'){
                    v.push_back(i);
                    string save;
                    for(int j = 0; j != i; j++){
                        save += s[j];
                    }
                    save += "01";
                    for(int j = i; j != s.size(); j++){
                        save += s[j];
                    }

                    s = save;
                }else{
                    v.push_back(p+1);
                    string save;
                    for(int j = 0; j <= p; j++){
                        save += s[j];
                    }
                    save += "01";
                    for(int j = p; j != s.size(); j++){
                        save += s[j];
                    }

                    s = save;
                }
                p+=2;
            }
            p--;
            if(i >= p){
                val = true;
                break;
            }
        }

        if(val){
            cout << cont << endl;
            for(auto it : v){
                cout << it << " ";
            }
            cout << endl;
        }else{
            cout << -1 << endl;
        }

    }
}