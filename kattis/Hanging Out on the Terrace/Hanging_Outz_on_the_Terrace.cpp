#include <iostream>
#include <string>

using namespace std;

int main(){
    int l, n;
    cin >> l >> n;

    int cont = 0;
    while(n--){
        int num;
        string s;

        cin >> s;
        cin >> num;

        if(s == "enter"){
            if(l - num < 0){
                cont++;
            }else{
                l -= num;
            }
        }else{
            l += num;
        }
    }

    cout << cont << endl;
}
