#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    int n;
    while(cin >> n){
        if(!n){
            break;
        }

        int mxl = 0, mxr = 0;
        vector<int> v;
        string s;
        getline(cin, s);
        int asw = 1e9;
        for(int i = 0; i != n; i++){
            getline(cin, s);
            
            int contb = 0;
            bool b = true;
            int cont = 0;
            for(int j = 0 ; j != s.size(); j++){
                if(s[j] != 'X'){
                    b = false;
                    cont = 0;
                }

                if(b){
                    cont++;
                    mxl = max(mxl, cont);
                }else if(!b && s[j] == 'X'){
                    cont++;
                    mxr = max(mxr, cont);
                }else{
                    contb++;
                }
            }    
            asw = min(asw, contb);
            v.push_back(contb);
        }

        asw = min(asw, max(25 - (mxr+mxl) + 2, 25));
        int cont = 0;
        for(auto it : v){
            cont += max(it-asw, 0);
        }

        cout << cont << endl;
    }
}
