#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(){
    string s;
    while(cin >> s){
        int cont = 0;

        map<string, bool> mp;
        for(int i = 0; i != s.size(); i++){
            for(int j = i; j != s.size(); j++) {
                string save;
                for(int k = i; k <= j; k++) {
                    save += s[k];
                }

                bool val = true;
                for(int k = 0; k <= save.size()/2; k++){
                    if(save[k] != save[save.size()-k-1]){
                        val = false;
                        break;
                    }
                }

                if(val && !mp[save]){
                    mp[save] = true;
                    cont++;
                }
            }
        }

        cout << "The string '"<< s << "' contains "<< cont <<" palindromes." << endl;
    }
}