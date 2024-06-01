#include <iostream>
#include <string>

using namespace std;

int main(){
    string s;
    while(getline(cin, s)){
        if(s == "DONE"){
            break;
        }
    
        string save="";
        for(auto it : s){
            if(isalpha(it)){
                save += tolower(it);
            }
        }

        bool p = true;
        for(int i = 0; i != save.size()/2; i++){
            if(save[i] != save[save.size()-i-1]){
                p=false;
                break;
            }
        }

        if(p){
            cout << "You won't be eaten!" << endl;
        }else{
            cout << "Uh oh.." << endl;
        }
    }
}
