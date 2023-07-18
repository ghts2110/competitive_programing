#include <iostream>

using namespace std;

int main(){
    int a, b;
    while(1){
        cin >> a >> b;

        if(a == 0 && b == 0){
            break;
        }

        if(a + b == 13){
            cout << "Never speak again." << endl;
        }else if(a == b){
            cout << "Undecided." << endl;
        }else if(a < b){
            cout << "Left beehind." << endl; 
        }else {
            cout << "To the convention." << endl;
        }
    }
}
