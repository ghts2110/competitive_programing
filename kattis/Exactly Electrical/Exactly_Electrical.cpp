#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int a, b, c, d;
    while(cin >> a >> b >> c >> d){


        int t;
        cin >> t;

        if(a == c & b == d && t != 0){
            cout << "N" << endl;
        }else if(abs(a-c) + abs(b-d) > t){
            cout << "N" << endl;
        }else if((abs(a-c) + abs(b-d)) % 2 != t % 2){
            cout << "N" << endl;
        }else{
            cout << "Y" << endl;
        }
    }
}
