#include <iostream>
#include <map>
#include <string>
#include <cmath>

using namespace std;

int main(){
    string s;
    map<char, int> mp;

    for(int i= 0; i != 5; i++){
        cin >> s;
        mp[s[0]]++;
    }

    int mx = max(mp['A'], mp['T']);
    mx = max(mx, mp['J']);
    mx = max(mx, mp['Q']);
    mx = max(mx, mp['K']);
    mx = max(mx, mp['2']);
    mx = max(mx, mp['3']);
    mx = max(mx, mp['4']);
    mx = max(mx, mp['5']);
    mx = max(mx, mp['6']);
    mx = max(mx, mp['7']);
    mx = max(mx, mp['8']);
    mx = max(mx, mp['9']);

    cout << mx << endl;
}
