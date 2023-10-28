#include <iostream>
#include <string>

using namespace std;

int main(){
    int test;
    cin >> test;

    while(test--){
        int n, m;
        cin >> n >> m;

        string s, t;
        cin >> s >> t;

        bool valT = true;
        for(int i = 1; i < m; i++){
            if(t[i] == t[i-1]){
                valT = false;
                break;
            }
        }

        bool valS = true;
        for(int i = 1; i != n; i++){
            if(s[i] == s[i-1]){
                if(!valT){
                    valS = false;
                    break;
                }

                if(s[i-1] == t[0] || s[i] == t[t.size()-1]){
                    valS = false;
                    break;
                }
            }
        }

        if(valS){
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }
    }
}