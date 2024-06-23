#include <iostream>
#include <string>

using namespace std;

int main(){
    string s;
    while(getline(cin, s)){
        if(s == "#"){
            break;
        }
        int sum = 0;
        for(auto it : s){
            sum = ((sum * 256) + it)%34943;
        }
        sum = ((34943 - ((sum*256)%34943*256))%34943 + 34943)%34943;
        printf("%02X %02X\n", sum/256, sum%256);
    }

}
