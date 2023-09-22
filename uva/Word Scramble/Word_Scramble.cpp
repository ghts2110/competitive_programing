#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    string s;
    while(getline(cin, s)){
        vector<int> v;
        v.push_back(-1);
        for(int i = 0; i != s.size(); i++){
            if(s[i] == ' '){
                v.push_back(i);
            }
        }
        v.push_back(s.size());

        for(int i = 1; i != v.size(); i++){
            string save = "";
            for(int j = v[i]-1; j != v[i-1]; j--){
                save += s[j];
            }

            if(i == v.size() -1){
                cout << save << endl;
                break;
            }
            cout << save << " ";
        }
    }
}