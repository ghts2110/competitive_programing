#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(){
    map<char, char> mp;
    mp['e'] = 'q';
    mp['r'] = 'w';
    mp['t'] = 'e';
    mp['y'] = 'r';
    mp['u'] = 't';
    mp['i'] = 'y';
    mp['o'] = 'u';
    mp['p'] = 'i';
    mp['['] = 'o';
    mp[']'] = 'p';
    mp['\\'] = '[';
    mp['d'] = 'a';
    mp['f'] = 's';
    mp['g'] = 'd';
    mp['h'] = 'f';
    mp['j'] = 'g';
    mp['k'] = 'h';
    mp['l'] = 'j';
    mp[';'] = 'k';
    mp['\''] = 'l';
    mp['c'] = 'z';
    mp['v'] = 'x';
    mp['b'] = 'c';
    mp['n'] = 'v';
    mp['m'] = 'b';
    mp[','] = 'n';
    mp['.'] = 'm';
    mp['/'] = ',';
    mp['2'] = '`';
    mp['3'] = '1';
    mp['4'] = '2';
    mp['5'] = '3';
    mp['6'] = '4';
    mp['7'] = '5';
    mp['8'] = '6';
    mp['9'] = '7';
    mp['0'] = '8';
    mp['-'] = '9';
    mp['='] = '0';
    mp[' '] = ' ';

    string s;
    while(getline(cin, s)){
        if(s == ""){
            continue;
        }
        for(auto it : s){
            cout << mp[tolower(it)]; 
        }
        cout << endl;
    }
}
