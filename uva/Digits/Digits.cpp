#include <iostream>
#include <cstring>
#include <string>
using namespace std;
int mem[1000010];
int dp(string s){
    if(mem[s.size()] != -1){
        return mem[s.size()];
    }

    return mem[s.size()] = dp(to_string(s.length())) + 1;
}

int main(){
    string s;
    memset(mem,-1,sizeof(mem));
    mem[1] = 2;
    while(cin >> s){
        if(s == "END"){
            break;
        }
        if(s == "1"){
            cout << 1 << endl;
            continue;
        }
        cout << dp(s) << endl;
    }

}