#include <iostream>
#include <string>

using namespace std;

int main(){
    string n,m;
    while(cin >> n >> m){
        if(n.size() >= m.size()){
            int sz1 = m.size()-1, sz2 = n.size(), cont = 0;
            for(int i = 0; i != sz1; i++){
                if(n[sz2-i-1] == '0'){
                    cont++;
                }else{
                    break;
                }
            }

            for(int i = 0; i != sz2-cont; i++){
                if(i == sz2-sz1){
                    cout << '.';
                }
                cout << n[i];
            }
            cout << endl;
        }else{
            int sz = m.size()-1;
            for(int i = 0; i <= sz-n.size(); i++){
                cout << 0;
                if(i == 0){
                    cout << ".";
                }
            }
            cout << n << endl;
        }
    }
}