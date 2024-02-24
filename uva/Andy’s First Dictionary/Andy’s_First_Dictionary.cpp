#include<iostream>
#include<string>
#include<set>
#include <ctype.h>
using namespace std;

int main(){
    string s;
    set<string> dic;

    while(getline(cin, s)){
        string s2="";    
        for(auto it : s){
            
            if(isalpha(it)){
                s2 += tolower(it);
            }
            if(!isalpha(it)&& !s2.empty()){
                dic.insert(s2);
                s2="";
            }

        }

        if(s2.empty()){
            continue;
        }
        dic.insert(s2);
    }

    for(auto it :  dic){
        if(it == " "){
            continue;
        }
        cout << it << endl;
    }
}    
