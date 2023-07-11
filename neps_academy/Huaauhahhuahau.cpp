#include <iostream>
#include <string>

using namespace std;

int main(){
    string s, vog = "";
    cin >> s;
    char c = 'S';

    for(int i = 0; i != s.size(); i++){
        if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'){
            vog += s[i];
        }
    }

    int start = 0, end = vog.size() - 1;

    for(int i = 0; i != vog.size(); i++){
        if(vog[start] != vog[end]){
            c = 'N';
        }

        start++;
        end--;
    }
    cout << c << endl;
}
