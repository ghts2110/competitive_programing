#include <iostream>
#include <string>

using namespace std;

int main(){
    string s;
    while(cin >> s){
        if(s == "0"){
            break;
        }

        int n = s.size();
        long long asw = 0;
        for(int i = 0; i != s.size(); i++){
            asw += (s[i]-'0') * ((1 << n)-1);
            n--;
        }

        cout << asw << endl;
    }
}
