#include <iostream>

using namespace std;

int f91(int n){
    if(n > 100){
        return n - 10;
    }else{
        n += 11;
        n = f91(n);
        return f91(n);
    }
}

int main(){
    int n;
    
    while(1){
        cin >> n;
        if(n == 0){
            break;
        }

        printf("f91(%d) = %d\n", n, f91(n));
    }
}
