#include <iostream>

using namespace std;

long long fac(long long x){
    if(x == 1){
        return 1;
    }

    return x * fac(x-1);
}

int main(){
    long long a, b;
    cin >> a >> b;

    int mn = min(a,b);
    cout << fac(mn) << endl;
}
