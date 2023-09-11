#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    int n;
    while(cin >> n){
        if(n == 0){
            break;
        }

        vector<string> v(n);
        int cont = -1;
        for(int i= 0; i != n; i++){
            string s1, s2;
            cin >> s1 >> s2;

            for(int j = 0; j != s2.size(); j++){
                cont++;
                if(cont >= n){
                    cont -= n;
                }

                while(v[cont] != ""){
                    cont++;
                    if(cont >= n){
                        cont -= n;
                    }
                }
            }



            v[cont] = s1;
        }

        for(int i = 0; i != v.size(); i++){
            if(i == v.size()-1){
                cout << v[i] << endl;
                break;
            }
            cout << v[i] << " ";
        }
    }
}