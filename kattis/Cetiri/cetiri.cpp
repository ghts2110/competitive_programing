#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int rry[3];
    cin >> rry[0] >> rry[1] >> rry[2];

    sort(rry, rry+3);
   
    int dif1 = rry[1] - rry[0], dif2 = rry[2] - rry[1];
    
    if(dif1 == dif2){
        cout << rry[2] + dif1 << endl;
    }else{
        if(rry[1] + (2*dif1) == rry[2]){
            cout << rry[1] + dif1 << endl;
        }else{
            cout << rry[1] - dif2 << endl;
        }
    }
}
