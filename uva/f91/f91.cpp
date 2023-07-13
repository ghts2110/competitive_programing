#include <iostream>
using namespace std;

int recursao(int n) {
    if(n <= 100){
        int number = recursao(n + 11);
        return recursao(number);
    }else{
        return n - 10;
    }
}

int main(){
    int n ;
    while(cin >> n && n != 0){
        int answer = recursao(n );
        printf("f91(%d) = %d\n", n, answer);
    }

    return 0;
}   
