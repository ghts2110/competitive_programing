#include <iostream>
#include <string>

using namespace std;

int main(){
    int t;
    cin >> t;
    
    string s;
    getline(cin, s);
    while(t--){
        getline(cin, s);

        int cm = 0, cf= 0;
        for(int i = 0; i != s.size(); i++){
            if(s[i] == 'M'){
                cm++;
            }else if(s[i] == 'F'){
                cf++;
            }
        }

        if(cm == cf && s.size() != 2){
            cout << "LOOP" << endl;
        }else{
            cout << "NO LOOP" << endl;
        }
    }
}
