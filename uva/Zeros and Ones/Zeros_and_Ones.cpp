#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main(){
    string s;
    int cont = 1;
    while(cin >> s){
        int n;
        cin >> n;

        cout << "Case "<<cont<<":" << endl;
        cont++;
        for(int i = 0; i != n; i++){
            int l, r;
            cin >> l >> r;

            int save = max(l, r);
            l = min(l, r);
            r =  save;

            bool validate = true;
            for(int j = l+1; j <= r; j++){
                if(s[j] != s[j-1]){
                    validate = false;
                }
            }

            if(validate){
                cout << "Yes" << endl;
            }else{
                cout << "No" << endl;
            }
        }
    }
}
