#include <iostream>
#include <cmath>

using namespace std;

int main(){
    double l1, l2, l3;
    while(cin >> l1 >> l2 >> l3){
        if(l1==0 && l2 == 0 && l3 == 0){
            break;
        }

        if(l1 > l2 && l1 > l3){
            if((l2*l2)+(l3*l3) == (l1*l1)){
                cout << "right" << endl;
            }else{
                cout << "wrong" << endl;
            }

        }else if(l2 > l3 && l2 > l1){
            if((l1*l1)+(l3*l3) == (l2*l2)){
                cout << "right" << endl;
            }else{
                cout << "wrong" << endl;
            }
        }else{
            if((l2*l2)+(l1*l1) == (l3*l3)){
                cout << "right" << endl;
            }else{
                cout << "wrong" << endl;
            }       
        }

    }
}
