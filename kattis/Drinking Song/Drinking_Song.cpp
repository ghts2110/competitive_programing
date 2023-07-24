#include <iostream>
#include <string>

using namespace std;

int main(){
    int t;
    cin >> t;
    
    string s;
    cin >> s;

    for(int i = t; i != 0; i--){
            
        if(i != 1){
            cout <<i<<" bottles of "<<s<<" on the wall, "<<i<<" bottles of "<<s<<"."<<endl;
            if(i != 2){
                cout << "Take one down, pass it around, "<<i-1<<" bottles of "<<s<<" on the wall."<<endl;
            }else{
                cout << "Take one down, pass it around, "<<i-1<<" bottle of "<<s<<" on the wall."<<endl;
            }
            cout << endl;
        }else{
            cout <<i<<" bottle of "<<s<<" on the wall, "<<i<<" bottle of "<<s<<"."<<endl;
            cout <<"Take it down, pass it around, no more bottles of "<<s<<"."<<endl;
        }
    }
}
