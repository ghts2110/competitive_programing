#include <iostream>
#include <string>

using namespace std;

int main(){
    int cont = 0;
    string s, c;

    getline(cin, s);
    getline(cin, c);

    int i, j;
    for(i = 0; i != s.size() - c.size() + 1; i++){
        int n = 0;
        for(j = 0; j != c.size(); j++){
            if(c[j] == s[i + j]){
                n = 1;
                break;
            }
        }

        if(n == 0){
            cont ++;
        }
    }

    cout << cont << endl;
}
