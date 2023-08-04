#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <map>

using namespace std;

int main(){
    string s;
    getline(cin, s);
        
    map<char, int> mp, l;
    mp['a'] = 0;
    mp['b'] = 1;
    mp['c'] = 2;
    mp['d'] = 3;
    mp['e'] = 4;
    mp['f'] = 5;
    mp['g'] = 6;
    mp['h'] = 7;
    l['1'] = 7;
    l['2'] = 6;
    l['3'] = 5;
    l['4'] = 4;
    l['5'] = 3;
    l['6'] = 2;
    l['7'] = 1;
    l['8'] = 0;

    s.erase(s.begin());
    vector<vector<char>> v(8, vector<char> (8));
    for(int i = 0; i < s.size(); i++){
        if((s[i] >= 'A' && s[i] <= 'Z') || (s[i] == ',' && s[i+1] >= 'a' && s[i+1] <= 'z')){
            if(s[i] == ','){
                s[i] = 'P';
            }
            v[mp[s[i+1]]][l[s[i+2]]] = s[i];
        }
    }

    getline(cin, s);
    s.erase(s.begin());

    for(int i = 0; i < s.size(); i++){
        if((s[i] >= 'A' && s[i] <= 'Z') || (s[i] == ',' && s[i+1] >= 'a' && s[i+1] <= 'z')){
            if(s[i] == ','){
                s[i] = 'p';
            }
            v[mp[s[i+1]]][l[s[i+2]]] = tolower(s[i]);
        }
    }

    for(int i = 0; i != 8; i++){
        for(int j = 0; j != 8; j++){
            if((i+j)%2 == 0 && v[i][j] == '\0'){
                v[i][j] = '.'; 
            }else if((i+j)%2 == 1 && v[i][j] == '\0'){
                v[i][j] = ':';
            }
        }
    }

    int line = -1;
    for(int i = 0; i != 17; i++){
        if(i %2 == 0){
            cout << "+---+---+---+---+---+---+---+---+" << endl;
            continue;
        }
        line++;

        if(line%2 == 0){
            cout << "|."<<v[0][line]<<".|:"<<v[1][line]<<":|.";
            cout << v[2][line]<<".|:"<<v[3][line]<<":|."<<v[4][line]<<".|:";
            cout << v[5][line]<<":|."<<v[6][line]<<".|:"<<v[7][line]<<":|" << endl;
        }else{
            cout << "|:"<<v[0][line]<<":|."<<v[1][line]<<".|:"<<v[2][line]<<":|.";
            cout << v[3][line]<<".|:"<<v[4][line]<<":|."<<v[5][line]<<".|:";
            cout << v[6][line]<<":|."<<v[7][line]<<".|" << endl;
        }
    }
}
