#include <iostream>
#include <string>

using namespace std;

int main(){
    string s;
    while(getline(cin, s)){
        string save = "";
        int asw = 0;
        for(auto it : s){
            if(isalpha(it)){
                save += it;
            }else if(save != ""){
                asw ++;
                save = "";
            }
        }

        cout << asw << endl;
    }
}
