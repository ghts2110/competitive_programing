#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    string s;
    while(cin >> s){
        if(s == "#"){
            break;
        }

        string save = s;
        sort(save.begin(), save.end());
        bool val = true, f = true;
        do{
            if(f){
                f=false;
                continue;
            }
            if(s == save){
                break;
            }
            val = false;
            cout << s << endl;
            break;
        }while(next_permutation(s.begin(), s.end()));
        
        if(val){
            cout << "No Successor" << endl;
        }
    }
}
