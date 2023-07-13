#include <iostream>

using namespace std;

int main(){
    int n, previous = 1, next = 1;

    cin >> n;
    if(n <= 1){
        cout << 1 << endl;
    }else{
        n--;
        while(n--){
            int save = next;
            next += previous;
            previous = save;
        }

        cout << next << endl;
    }
}
