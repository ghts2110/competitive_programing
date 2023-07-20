#include <iostream>

using namespace std;

int main(){
    int t;
    cin >> t;

    int mn = 1e9, d = 0;
    for(int i = 0; i != t; i++){
        int num;
        cin >> num;

        if(mn > num){
            d = i;
            mn = num;
        }
    }

    cout << d << endl;
}
