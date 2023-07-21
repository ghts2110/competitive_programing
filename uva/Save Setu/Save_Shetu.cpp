#include <iostream>
#include <string>

using namespace std;

int main(){
    int t;
    cin >> t;

    int cont = 0;
    while(t--){
        string s;
        cin >> s;

        if(s == "report"){
            cout << cont << endl;
        }else{
            int num;
            cin >> num;
            cont += num;
        }
    }
}
