#include <iostream>
#include <string>

using namespace std;

int main(){
    int cont = 0;
    string n;

    cin >> n;
    
    for(int i = 0; i != n.size(); i++){
        if(n[i] == '4' || n[i] == '7'){
            cont++;
        }
    }

    n = to_string(cont);
    
    for(int i = 0; i != n.size(); i++){
        if(n[i] != '4' && n[i] != '7'){
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
}
