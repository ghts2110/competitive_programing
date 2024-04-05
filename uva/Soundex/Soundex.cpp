#include <iostream>
#include <map>
#include <string>
using namespace std;

int main(){
    string s;

    map<char,char>mp;

    mp['B'] = '1';
    mp['F'] = '1';
    mp['P'] = '1';
    mp['V'] = '1';

    mp['C'] = '2';
    mp['G'] = '2';
    mp['J'] = '2';
    mp['K'] = '2';
    mp['Q'] = '2';
    mp['S'] = '2';
    mp['X'] = '2';
    mp['Z'] = '2';
   
    mp['D'] = '3';
    mp['T'] = '3';
    
    mp['L'] = '4';

    mp['M'] = '5';
    mp['N'] = '5';

    mp['R'] = '6';

    while(cin >> s){
        string aux = "";
        for(int i = 0; i < s.size(); i++){
            if(mp.find(s[i]) != mp.end()){
                if(i == 0 ){
                    aux += mp[s[i]];
                }else if((mp.find(s[i-1]) == mp.end()) || (mp[s[i-1]] != mp[s[i]])){
                   aux += mp[s[i]]; 
                }
            }
        }

        cout << aux << endl;
    }
}

