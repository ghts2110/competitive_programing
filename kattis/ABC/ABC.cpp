#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    int rry[3];
    cin >> rry[0] >> rry[1] >> rry[2];
    
    sort(rry, rry + 3);
    
    string s;
    cin >> s;

    for(char i : s){
        if(i == 'A'){
            cout << rry[0] << " ";
        }

        if(i == 'B'){
            cout << rry[1] << " ";
        }

        if(i == 'C'){
            cout << rry[2] << " ";
        }
    }

    cout << endl;
}
