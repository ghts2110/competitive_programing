#include <iostream>

using namespace std;

int main(){
    int a = 0, b =0, n;
    
    cin >> n;
    while(n--){
        int num;
        cin >> num;

        if(num == 1){
            a ^= 1;
        }else{
            a ^= 1;
            b ^= 1;
        }
    }

    cout << a << endl << b << endl;
}
