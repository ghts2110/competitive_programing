#include <iostream>

using namespace std;

int main(){
    long long a, b;
    while(cin >> a >> b){
        long long sub = a - b;
        if(sub < 0){
            sub *= -1;
        }

        cout << sub << endl;
    }
}
