#include <iostream>
#include <string>

using namespace std;

int main(){
    int t;
    cin >> t;

    int f = true;
    while(t--){
        if(!f){
            cout << endl;
        }
        f=false;

        string s;
        cin >> s;

        for(int i = 1; i <= s.size(); i++){
            if(s.size() % i != 0){
                continue;
            }

            string save = "";
            for(int j = 0; j != i; j++){
                save += s[j];
            }

            int j = i;
            bool equal = true;
            while(j < s.size()){
                string comp = "";
                for(int k = j; k != j+i; k++){
                    comp+=s[k];
                }
                j+=i;
                if(comp.compare(save) != 0){
                    equal = false;
                    break;
                }
            }

            if(equal){
                cout << i << endl;
                break;
            }
        }

    }
}
