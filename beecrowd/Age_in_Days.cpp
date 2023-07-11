#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;

    int y = n/365;
    n %= 365;
    int m = n / 30;
    n %= 30; 
    int d = n;

    cout << y << " ano(s)" << endl;
    cout << m << " mes(es)" << endl;
    cout << d << " dia(s)" << endl;
}
