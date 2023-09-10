#include <iostream>
#include <string>

using namespace std;

int main(){
    string s;
    while(cin >> s){
        int asw =  -1, cont = 0;
        for(auto it : s){
            cont++;

            if(it != '.'){
                if(asw == -1){
                    asw = cont-1;
                    cont = 1;
                    continue;
                }

                if(cont % 2 == 0){
                    cont--;
                }
                asw = max(asw, cont/2);
                cont = 1;
            }
        }
        asw = max(asw, cont-1);

        cout << asw -1 << endl;
    }
}