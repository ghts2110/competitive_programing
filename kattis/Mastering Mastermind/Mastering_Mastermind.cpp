#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(){
    int t;
    while(cin >> t){
        string s1, s2;
        cin >> s1 >> s2;

        int contC = 0;
        map<char, int> mp;

        for(int i = 0; i != t; i++){
            if(s1[i] == s2[i]){
                s1.erase(s1.begin()+i);
                s2.erase(s2.begin()+i);
                contC++;
                i--;
                t--;
            }else{
                mp[s1[i]]++;
            }
        }

        int cont = 0;
        for(char c : s2){
            if(mp[c] > 0){
                mp[c]--;
                cont++;
            }
        }

        cout << contC << " " << cont << endl;
    }
}