#include <iostream>

using namespace std;

int main(){
    long long n;
    while(cin >> n){
        if(n < 0){
            break;
        }

        long long asw = (1+n)*(n/2);
        if(n%2 == 1){
            asw += (n/2)+1;
        }

        cout << asw+1  << endl;
    }
}
