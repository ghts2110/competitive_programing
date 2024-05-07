#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    string s;
    vector<string> v;
    int mx = 0;
    while(getline(cin, s)){
        if(s == ""){
            break;
        }
        v.push_back(s);
        mx = max(mx, (int)s.size());
    }
    for(auto &it : v){
        while(it.size() != mx){
            it+=' ';
        }
    }
    for(int i = 0; i != mx; i++){
        for(int j = v.size()-1; j != -1; j--){
            cout << v[j][i];
        }
        cout << endl;
    }
}
