#include <iostream>
#include <string>

using namespace std;

int main(){
    string s1, s2;
    while(cin >> s1 >> s2){
        if(s1 == s2 && s2 == "0"){
            break;
        }

        int mx = max(s1.size(), s2.size());
        while(s1.size() != mx){
            s1 = '0' + s1;
        }
        while(s2.size() != mx){
            s2 = '0' + s2;
        }

        int asw = 0;
        int p = 0;
        for(int i = mx-1; i != -1; i--){
            if(s1[i]-'0' + s2[i]-'0' + p >= 10){
                asw++;
                p = 1;
                continue;
            }
            p = 0;
        }

        if(asw == 0){
            cout << "No carry operation." << endl;
        }else if(asw == 1){
            cout << asw << " carry operation." << endl;
        }else{
            cout << asw << " carry operations." << endl;
        }
    }
}
