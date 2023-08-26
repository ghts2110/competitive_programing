#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(){
    int t;
    string s;
    cin >> t;
    
    getline(cin, s);
    
    map<char, int> mp;
    mp['a'] = 1;
    mp['d'] = 1;
    mp['g'] = 1;
    mp['j'] = 1;
    mp['m'] = 1;
    mp['p'] = 1;
    mp['t'] = 1;
    mp['w'] = 1;
    mp['b'] = 2;
    mp['e'] = 2;
    mp['h'] = 2;
    mp['k'] = 2;
    mp['n'] = 2;
    mp['q'] = 2;
    mp['u'] = 2;
    mp['x'] = 2;
    mp['c'] = 3;
    mp['f'] = 3;
    mp['i'] = 3;
    mp['l'] = 3;
    mp['o'] = 3;
    mp['r'] = 3;
    mp['v'] = 3;
    mp['y'] = 3;
    mp['s'] = 4;
    mp['z'] = 4;
    mp[' '] = 1;

    for(int test = 1; test <= t; test++){
        cout << "Case #"<<test<<": ";
        getline(cin, s);
        int cont = 0;
        
        for(int i = 0; i != s.size(); i++){
            cont += mp[s[i]]; 
        }

        cout << cont << endl;
    }
}
