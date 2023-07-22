#include <iostream>
#include <string>

using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        string s;
        cin >> s;

        int sum = 0, cont = 0;
        for(int i = 0; i != s.size(); i++){
            if(s[i] == 'O'){
                cont++;
            }else{
                cont = 0;
            }

            sum += cont;
        }

        cout << sum << endl;
    }
}
