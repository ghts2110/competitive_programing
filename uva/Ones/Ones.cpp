#include <iostream>

using namespace std;

int main(){
    int n;
    while(cin >> n){
        int asw = 1, num = 1;

        if(n == 1){
            num = 0;
        }
        
        while(num != 0){
            asw++;
            num = (num*10+1)%n;
        }

        cout << asw << endl;
    }
}
