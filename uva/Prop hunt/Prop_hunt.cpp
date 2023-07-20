#include <iostream>

using namespace std;

int main(){
    int a, b, c;
    while(cin >> a >> b >> c){
        if(c-a >= b){
            cout << "Props win!" << endl;
        }else{
            cout << "Hunters win!" << endl;
        }
    }
}
