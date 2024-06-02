#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    string s;
    while(cin >> s){
        vector<int> v; 
        for(int i = s.size()-1;i != -1; i--){
            if(s[i] == '['){
                v.push_back(i);
            }
        }
        
        v.push_back(-1);
        for(int i = 0; i != s.size(); i++){
            if(s[i] == ']'){
                v.push_back(i);
            }
        }

        string asw = "";
        for(auto it : v){
            it++;
            while(it != s.size() && s[it] != '[' && s[it] != ']'){
                asw += s[it];
                it++;
            }
        }

        cout << asw << endl;
    }
}
