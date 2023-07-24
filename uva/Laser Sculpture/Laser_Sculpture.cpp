#include <iostream>

using namespace std;

int main(){
    int a, c;
    while(cin >> a >> c){
        if(a == 0){
            break;
        }

        int num, cont, l;
        cin >> num;
        l = cont = a-num;

        for(int i = 1; i != c; i++){
            cin >> num;
            if(l < a-num){
                cont += a-num-l;
            }

            l = a-num;
        }

        cout << cont << endl;
    }
}
