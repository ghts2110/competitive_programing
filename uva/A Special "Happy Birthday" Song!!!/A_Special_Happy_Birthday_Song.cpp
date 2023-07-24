#include <iostream>
#include <vector>
#include <string>

#define pb push_back

using namespace std;

int main(){
    int t;
    cin >> t;

    string s;
    vector<string> v;
    for(int i = 0; i != t; i++){
        cin >> s;
        v.pb(s);
    }

    vector<string> m;
    m.pb(": Happy");
    m.pb(": birthday");
    m.pb(": to");
    m.pb(": you");
    m.pb(": Happy");
    m.pb(": birthday");
    m.pb(": to");
    m.pb(": you");
    m.pb(": Happy");
    m.pb(": birthday");
    m.pb(": to");
    m.pb(": Rujia");
    m.pb(": Happy");
    m.pb(": birthday");
    m.pb(": to");
    m.pb(": you");

    int index = 0;
    for(int i = 0; i != t; i++){
        cout << v[i] << m[index] << endl;
        index++;

        if(index == 16){
            index = 0;
        }
    }
    
    int j = 0;
    for(int i = index; i != 16; i++){
        cout << v[j] << m[i] << endl;
        j++;

        if(j == t){
            j = 0;
        }
    }


}
