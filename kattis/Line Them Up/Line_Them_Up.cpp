#include <iostream>
#include <string>

using namespace std;

int main(){
    int t;
    cin >> t;

    string s1, s2;
    cin >> s1 >> s2;
    
    char l;
    if(s1 > s2){
        l = 'd'; 
    }else{
        l = 'i';
    }

    t -= 2;
    s1 = s2;
    bool validate = true;
    for(int i = 0; i != t; i++){
        cin >> s2;
        if(l == 'd' && s1 < s2){
            validate = false;
            break;
        }

        if(l == 'i' && s1 > s2){
            validate = false;
            break;
        }
    }

    if(l == 'd' && validate){
        cout << "DECREASING" << endl;
    }else if(l == 'i' && validate){
        cout << "INCREASING" << endl;
    }else{
        cout << "NEITHER" << endl;
    }
}
