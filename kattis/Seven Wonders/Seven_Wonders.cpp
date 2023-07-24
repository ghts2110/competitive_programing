#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main(){
    string s;
    while(cin >> s){
        int t = 0, c = 0, g = 0;
        for(int i = 0; i != s.size(); i++){
            if(s[i] == 'T'){
                t++;
            }else if(s[i] == 'C'){
                c++;
            }else{
                g++;
            }
        }

        int mn = min(t, c);
        mn = min(mn, g);

        cout << (t*t)+(c*c)+(g*g)+(7*mn) << endl;
    }
    
}
