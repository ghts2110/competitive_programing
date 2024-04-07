#include <iostream>
#include <string>

using namespace std;

int main(){
    string s;
    while(getline(cin, s)){
        for(auto it : s){
            cout << char(it-7);
        }
        cout << endl;
    }
}
