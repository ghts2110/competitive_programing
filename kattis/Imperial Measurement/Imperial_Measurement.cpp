#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

int main(){
    map<string, int> mp;
    mp["thou"] = 0;
    mp["th"] = 0;
    mp["inch"] = 1;
    mp["in"] =1;
    mp["foot"] = 2;
    mp["ft"] = 2;
    mp["yard"] = 3;
    mp["yd"] = 3;
    mp["chain"] = 4;
    mp["ch"] =4;
    mp["furlong"] = 5;
    mp["fur"] = 5;
    mp["mile"] = 6;
    mp["mi"] = 6;
    mp["league"] = 7;
    mp["lea"] = 7;

    map<int, int> conv;
    conv[0] = 1;
    conv[1] = 1000;
    conv[2] = 12;
    conv[3] = 3;
    conv[4] = 22;
    conv[5] = 10;;
    conv[6] = 8; 
    conv[7] = 3;

    double v, j;
    string x, y;
    while(cin >> v >> x >> y >> y){
        if(mp[x] > mp[y]){
            j = -1;
        }else if(mp[x] < mp[y]){
            j = 1;
        }else{
            cout << v << endl;
            return 0;
        }

        for(int i = mp[x]; i != mp[y]; i += j){
            if(j == 1){
                v/=conv[i+1];
            }else{
                v*=conv[i];
            }
        }

        printf("%.9f\n", v);
    }
}
