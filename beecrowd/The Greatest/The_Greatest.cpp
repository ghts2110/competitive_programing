#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int a, b, c;
    cin >> a >> b >> c;

    a = max(a,b);
    cout << max(a, c) << " eh o maior" << endl;
}
