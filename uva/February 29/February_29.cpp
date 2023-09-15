#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(){
    map<string, int> mp;
    mp["January"] = 1;
    mp["February"] = 2;
    mp["March"] = 3;
    mp["April"] = 4;
    mp["May"] = 5;
    mp["June"] = 6;
    mp["July"] = 7;
    mp["August"] = 8;
    mp["September"] = 9;
    mp["October"] = 10;
    mp["November"] = 11;
    mp["December"] = 12;

    int t;
    cin >> t;

    for(int test = 1; test <= t; test++){
        long long cont = 0;

        string s;
        long long d1, d2, m1, m2, a1, a2;
        cin >> s;
        m1 = mp[s];
        scanf("%lld, %lld", &d1, &a1);
        cin >> s;
        m2 = mp[s];
        scanf("%lld, %lld", &d2, &a2);

        long long d4 = (a2/4)-(a1/4), d100 = (a2/100)-(a1/100), d400 = (a2/400)-(a1/400);
        if(a1%4 == 0){
            d4++;
        }
        if(a1%100 == 0){
            d100++;
        }
        if(a1%400 == 0){
            d400++;
        }


        cont += d4 - (d100-d400);

        if(a1%4==0){
            if(a1%400 == 0 || a1%100 != 0){
                if(m1 > 2){
                    cont--;
                }
            }
        }
        if(a2%4==0){
            if(a2%400 == 0 || a2%100 != 0){
                if(m2 == 2 && d2 < 29){
                    cont--;
                }else if(m2 < 2){
                    cont--;
                }
            }
        }

        cout << "Case "<<test<<": "<<cont << endl;
    }
}