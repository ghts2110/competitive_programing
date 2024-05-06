#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(){
    string s;
    map<char, char> mp;
    mp['A'] = 'A';
    mp['E'] = '3';
    mp['H'] = 'H';
    mp['I'] = 'I';
    mp['J'] = 'L';
    mp['L'] = 'J';
    mp['M'] = 'M';
    mp['O'] = 'O';
    mp['S'] = '2';
    mp['T'] = 'T';
    mp['U'] = 'U';
    mp['V'] = 'V';
    mp['W'] = 'W';
    mp['X'] = 'X';
    mp['Y'] = 'Y';
    mp['Z'] = '5';
    mp['1'] = '1';
    mp['2'] = 'S';
    mp['3'] = 'E';
    mp['5'] = 'Z';
    mp['8'] = '8';

    while(cin >> s){

        bool m = true;
        bool p = true;


        for(int i = 0; i != s.size()/2; i++){
            if(s[i] != s[s.size()-i-1]){
                p = false;
                break;
            }
        }

        for(int i = 0; i <= s.size()/2; i++){
            if(i == s.size()/2 && mp[s[i]] != s[i] && s.size() % 2 == 1){
                m = false;
                break;
            }else if(mp[s[i]] != s[s.size()-i-1]){
                m = false;
                break;
            }
        }


        if(!m && !p){
            cout << s << " -- is not a palindrome." << endl;
        }else if(!m && p){
            cout << s << " -- is a regular palindrome." << endl;
        }else if(m && !p){
            cout << s << " -- is a mirrored string." << endl;
        }else{
            cout << s << " -- is a mirrored palindrome." << endl;
        }
        cout << endl;
    }
}
