#include <iostream>
#include <string>
#include <vector>

#define pb push_back

using namespace std;

int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
        
    vector<string> v;
    int mx = 0;
    for(int i = 0; i != n; i++){
        if(i % 3 == 0 && s[i] == 'A'){
            mx++;
        }else if(i % 3 == 1 && s[i] == 'B'){
            mx++;
        }else if(i % 3 == 2 && s[i] == 'C'){
            mx++;
        }
    }
    v.pb("Adrian");

    int cont = 0, j = 0;
    for(int i = 0; i != n; i++){
        if(i % 2 == 0 && s[i] == 'B'){
            cont++;
        }
        if(i % 2 == 1){
            if(j % 2 == 0 && s[i] == 'A'){
                cont++;
            }else if(j % 2 == 1 && s[i] == 'C'){
                cont++;
            }
            j++;
        }
    }

    if(cont == mx){
        v.pb("Bruno");
    }else if(cont > mx){
        mx = cont;
        v.clear();
        v.pb("Bruno");
    }

    j = cont = 0;
    for(int i = 0; i != n; i++){
        if(j % 3 == 0 && s[i] == 'C'){
            cont++;
        }else if(j % 3 == 1 && s[i] == 'A'){
            cont++;
        }else if(j % 3 == 2 && s[i] == 'B'){
            cont++;
        }

        if(i % 2 == 1){
            j++;
        }
    }

    if(cont == mx){
        v.pb("Goran");
    }else if(cont > mx){
        mx = cont;
        v.clear();
        v.pb("Goran");
    }
    
    cout << mx << endl;
    for(int i = 0; i != v.size(); i++){
        cout << v[i] << endl;        
    }
}
