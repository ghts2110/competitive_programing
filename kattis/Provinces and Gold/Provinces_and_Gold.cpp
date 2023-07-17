#include <iostream>

using namespace std;

int main(){
    int a, b, c;
    cin >> a >> b >> c;

    int cont = (a*3) + (b*2) + (c*1);
    if(cont >= 8){
        cout << "Province or ";
    }else if(cont >= 5){
        cout << "Duchy or ";
    }else if(cont >= 2){
        cout << "Estate or ";
    }

    if(cont >= 6){
        cout << "Gold" << endl;
    }else if(cont >= 3){
        cout << "Silver" << endl;
    }else{
        cout << "Copper" << endl;
    }

}
