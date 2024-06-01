#include <iostream>
#include <string>

using namespace std;

int main(){
    int n;
    while(cin >> n){
        if(n==0){
            break;
        }
    
        string s;
        cin >> s;

        int g = s.size()/n;

        string save = "";
        for(int i = 0; i != s.size(); i++){
            if(i % g == 0){
                cout << save;
                save = "";
            }

            save = s[i] + save;
        }
        cout << save << endl;
    }
}
