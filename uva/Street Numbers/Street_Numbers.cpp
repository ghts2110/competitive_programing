#include <iostream>

using namespace std;

int main(){
    long long cont = 0, num= 3, h = 2;
    while(cont != 10){
        long long l = (h * (h-1))/2, r = ((h+1+num)*(num - (h +1) + 1))/2;
        if(l == r){
            cont ++;
            printf("%10lld %9lld\n", h, num);
            num++;
        }else if(l < r){
            num++;
            h++;
        }else{
            num++;
        }
    }
}
