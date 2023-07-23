#include <iostream>
#include <string>
#include <vector>

#define pb push_back

using namespace std;

int main(){
    int n;
    cin >> n;

    string s;
    vector<string> v;
    for(int i = 0; i != 5; i++){
        cin >> s;
        v.pb(s);
    }

    for(int i = 0; i != v[0].size(); i++){
        if(v[0][i] == '*'){
            int cont = 0;
            for(int j = 0; j != 5; j++){
                if(v[j][i] == '*'){
                    cont++;
                }
            }

            if(cont == 5){
                cout << 1;
            }else if(cont == 4){
                cout << 2;
                v[0][i+1] = '.';
                v[0][i+2] = '.';
            }else{
                cout << 3;
                v[0][i+1] = '.';
                v[0][i+2] = '.';
            }
        }
    }

    cout << endl;
}
