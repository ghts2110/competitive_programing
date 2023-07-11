#include <iostream>

using namespace std;

int main(){
    int a, b, c;
    cin >> a;
    cin >> b;
    cin >> c;

    if((a == 0 || b == 0 || c == 0) || (a == b || a == c || b == c) || (a + b == c || a - b == c) || (a + c == b || a - c == b) || (b + c == a || b - c == a)){
        cout << "S" << endl;
    }else{
        cout << "N" << endl;
    }

}
