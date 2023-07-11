#include <iostream>
#include <string>
 
using namespace std;
 
int main(){
    string s;
    int m, cont = 0;
    int dp[100000];
    cin >> s >> m;
 
    dp[0] = 0;
    for(int i = 0; i != s.size(); i++){
        if(s[i] == s[i+1]){
            cont++;
        }
        dp[i+1] =cont;
    } 
 
    while(m--){
        int l, r;
        cin >> l >> r;
        l--;
        r--;
 
        cont = dp[r] - dp[l]; 
        
        cout << cont << endl;
    }
}
