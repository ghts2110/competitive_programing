#include <iostream>
#include <string>

using namespace std;
int n;
bool asw = false;

int build(int ind, int cont){
    char c;
    string s = "";
    bool val = false;
    int leaf = -2;
    while(cin >> c){
        if(c == '('){
            if(!val){
                leaf += build(ind*2+1, cont + stoi(s));
            }else{
                leaf += build(ind*2+2, cont + stoi(s));
            }
            val = true;
            continue;
        }
        if(c == ')'){
            if(leaf == 0 && cont+stoi(s) == n){
                asw = true;
            }
            if(s == ""){
                return 1;
            }else{
                return 3;
            }
        }

        s += c;
    }
    return 0;
}

int main(){
    while(cin >> n){
        char c;
        asw = false;
        cin >> c;
        build(0, 0);

        if(asw){
            cout << "yes" << endl;
        }else{
            cout << "no" << endl;
        }
    }
}
