#include <iostream>

using namespace std;

int main(){
    int a, b, c, n;
    cin >> a >> b >> c >> n;

    if(n < 3){
        cout << "NO" << endl;
        return 0;
    }

    if(a == 0 || b == 0 || c == 0 || a + b + c < n){
        cout << "NO" << endl;
        return 0;
    }

    cout << "YES" << endl;
}
