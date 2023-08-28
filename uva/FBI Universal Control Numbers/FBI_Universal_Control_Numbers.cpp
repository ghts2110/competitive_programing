#include <iostream>
#include <string>
#include <cmath>
#include <map>

using namespace std;

int main(){
    map<char, int> mp;
    mp['0'] = 0;
    mp['1'] = 1;
    mp['2'] = 2;
    mp['3'] = 3;
    mp['4'] = 4;
    mp['5'] = 5;
    mp['6'] = 6;
    mp['7'] = 7;
    mp['8'] = 8;
    mp['9'] = 9;
    mp['A'] = 10;
    mp['B'] = 8;
    mp['C'] = 11;
    mp['D'] = 12;
    mp['E'] = 13;
    mp['F'] = 14;
    mp['G'] = 11;
    mp['H'] = 15;
    mp['I'] = 1;
    mp['J'] = 16;
    mp['K'] = 17;
    mp['L'] = 18;
    mp['M'] = 19;
    mp['N'] = 20;
    mp['O'] = 0;
    mp['P'] = 21;
    mp['Q'] = 0;
    mp['R'] = 22;
    mp['S'] = 5;
    mp['T'] = 23;
    mp['U'] = 24;
    mp['V'] = 24;
    mp['W'] = 25;
    mp['X'] = 26;
    mp['Y'] = 24;
    mp['Z'] = 2;

    int t;
    cin >> t;

    while(t--){
        int k;
        string s;

        cin >> k >> s;
        long long cont= 0;
        int rry[] = {2, 4, 5, 7, 8, 10, 11, 13};

        for(int i = 0; i != 8; i++ ){
            cont += rry[i] * mp[s[i]];
        }
        cont %= 27;

        cout << k << " ";

        if((mp.find(s[8]) != mp.end() && cont == mp[s[8]]) || (mp.find(s[8]) == mp.end() && cont == s[8]-'0')){
            cont = 0;
            for(int i = 0; i != 8; i++){
                cont += pow(27, i) * mp[s[7-i]];
            }
            cout << cont << endl;
        }else{
            cout << "Invalid" << endl;
        }
    }
}
