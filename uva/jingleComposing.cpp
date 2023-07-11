#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main(){
    string comp;
    while(1){
        cin >> comp;

        if( comp[0] == '*' ){
            break;
        }
        vector<char> v;
        map<char, float> mp;

        mp['W'] = 1;
        mp['H'] = 0.5;
        mp['Q'] = 0.25;
        mp['E'] = 0.125;
        mp['S'] = 0.0625;
        mp['T'] = 0.03125;
        mp['X'] = 0.015625;

        float cont = 0;
        int value = 0;
        for(int i = 1; i != comp.size(); i++){
            if(comp[i] == '/'){
                if(cont == 1){
                    value++;
                }
                cont = 0;
                continue;
            }

            cont += mp[comp[i]];
        }

        cout << value << endl;
    }
}
