#include <iostream>
#include <string>
#include <map>
#include <cmath>

using namespace std;

int main(){
    string s;
    map<char, int> m;
    m['a'] = 1;
    m['b'] = 2;
    m['c'] = 3;
    m['d'] = 4;
    m['e'] = 5;
    m['f'] = 6;
    m['g'] = 7;
    m['h'] = 8;
    m['i'] = 9;
    m['j'] = 10;
    m['k'] = 11;
    m['l'] = 12;
    m['m'] = 13;
    m['n'] = 14;
    m['o'] = 15;
    m['p'] = 16;
    m['q'] = 17;
    m['r'] = 18;
    m['s'] = 19;
    m['t'] = 20;
    m['u'] = 21;
    m['v'] = 22;
    m['w'] = 23;
    m['x'] = 24;
    m['y'] = 25;
    m['z'] = 26;
    m['A'] = 27;
    m['B'] = 28;
    m['C'] = 29;
    m['D'] = 30;
    m['E'] = 31;
    m['F'] = 32;
    m['G'] = 33;
    m['H'] = 34;
    m['I'] = 35;
    m['J'] = 36;
    m['K'] = 37;
    m['L'] = 38;
    m['M'] = 39;
    m['N'] = 40;
    m['O'] = 41;
    m['P'] = 42;
    m['Q'] = 43;
    m['R'] = 44;
    m['S'] = 45;
    m['T'] = 46;
    m['U'] = 47;
    m['V'] = 48;
    m['W'] = 49;
    m['X'] = 50;
    m['Y'] = 51;
    m['Z'] = 52;

    while(cin >> s){
        int cont = 0;
        for(int i = 0; i != s.size(); i++){
            cont += m[s[i]];
        }

        int isp = 1;
        for(int i = 2; i <= sqrt(cont); i++){
            if(cont % i == 0){
                isp = 0;
                break;
            }
        }
        
        if(isp == 1){
            cout << "It is a prime word." << endl;
        }else{
            cout << "It is not a prime word." << endl;
        }
    }
}
