#include <iostream>
#include <string>

using namespace std;

int main(){
    string s;

    while(1){
        cin >> s;
        if(s == "END"){
            break;
        }

        if(s == "1"){
            cout << 1 << endl;
            continue;
        }

        int l = s.size(), r = 0, cont = 2, n = 1;
        while(n <= l){
            n *= 10;
            r++;
        }

        while(l != r){
            cont++;
            l = r;
            n = 1;
            r = 0;
            while(n <= l){
                n *= 10;
                r++;
            }
        }

        cout << cont << endl;
    }
}
