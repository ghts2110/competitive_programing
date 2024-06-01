#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
    
        map<char, int> mp;
        for(int i = 0; i != n; i++){
            char c;
            int num;
            cin >> c >> num;
            mp[c] = num;
        }

        int m;
        cin >> m;

        int asw = 0;
        string s;
        getline(cin,s);
        for(int i= 0; i != m ;i++){
            getline(cin, s);
            for(auto it : s){
                asw += mp[it];
            }
        }

        printf("%.2lf$\n", asw/100.0);
    }
}
