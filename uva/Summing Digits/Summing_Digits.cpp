#include <iostream>

using namespace std;

int f(int n){
    int save = 0;
    while(n != 0){
        save += n %10;
        n /= 10;
    }

    n = save;

    if(n >= 10){
        return f(n);
    }

    return n;
}

int main(){
    int n;
    while(1){
        cin >> n;

        if(n == 0){
            break;
        }

        cout << f(n) << endl;
    }
}
