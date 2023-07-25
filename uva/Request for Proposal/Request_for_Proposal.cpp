#include <iostream>
#include <string>

using namespace std;

int main(){
    int n, p;
    int cont = 1;
    while(cin >> n >> p){
        if(p == 0 && n == 0){
            break;
        }

        if(cont != 1){
            cout << endl;
        }

        string s;
        getline(cin, s);
        for(int i = 0; i != n; i++){
            getline(cin, s);
        }

        string name, value;
        int mx = 0, mn = 1e9;
        for(int i = 0; i != p; i++){
            getline(cin, name);

            float d;
            int r;
            cin >> d >> r;
        
            getline(cin, s);
            for(int j = 0; j != r; j++){
                getline(cin, s);
            }

            if(r >= mx){
                if(r == mx && d >= mn){
                    continue;
                }
                mx = r;
                mn = d;
                value = name;
            }
        }
         
        cout << "RFP #" << cont << endl;
        cont++;
        cout << value << endl;
    }
}
