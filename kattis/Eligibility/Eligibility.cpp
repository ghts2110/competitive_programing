#include <iostream>
#include <string>

using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        string s;
        cin >> s;

        int de, me, ye;
        scanf("%d/%d/%d", &ye, &me, &de);
        int dn, mn, yn;
        scanf("%d/%d/%d", &yn, &mn, &dn);
        int c;
        cin >> c;

        if(yn >= 1991 || ye >= 2010){
            cout << s << " eligible" << endl;
        }else if(c > 40){
            cout << s << " ineligible" << endl;
        }else{
            cout << s << " coach petitions" << endl;
        }
    }
}
