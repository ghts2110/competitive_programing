#include <iostream>
#include <string>

using namespace std;

int main(){
    int t;
    cin >> t;

    bool v = true;
    for(int i = 1; i <= t; i++){
        string s;
        cin >> s;

        if(s == "mumble"){
            continue;
        }

        if(s != to_string(i)){
           v = false; 
        }
    }

    if(v){
        cout << "makes sense" << endl;
    }else{
        cout << "something is fishy" << endl; 
    }
}
