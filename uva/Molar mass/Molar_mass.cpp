#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(){
    int t;
    cin >> t;

    map<char, double> mp;
    mp['C'] = 12.01;
    mp['H'] = 1.008;
    mp['O'] = 16;
    mp['N'] = 14.01; 
    while(t--){
        string s;
        cin >> s;
        
        double cont = 0;
        for(int i = 0; i != s.size(); i++){
            if(s[i] < 'A' || s[i] > 'Z'){
                continue;
            }

            double mult = 1;
            if(i+1 < s.size() && (s[i+1]<'A'||s[i+1]>'Z')){
                mult = s[i+1]-'0';
                if(i+2 < s.size() && (s[i+2]<'A'||s[i+2]>'Z')){
                    mult *= 10;
                    mult += s[i+2] -'0';
                }
            }
            cont += mp[s[i]] * mult;
        } 

        printf("%.3f\n", cont);
    }
}
