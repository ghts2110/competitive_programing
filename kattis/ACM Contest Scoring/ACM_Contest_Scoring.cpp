#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(){
    int m;
    string s;
    char p;

    int soluve = 0, t = 0;
    map<char, int> mp;

    while(cin >> m >> p >> s){
        if(m == -1){
            break;
        }

        if(s == "wrong"){
            mp[p]++;
        }else{
            soluve++;
            t += m + (20 * mp[p]);
        }
    }

    cout << soluve << " " << t << endl;
}
