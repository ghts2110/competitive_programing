#include <iostream>
#include <cmath>

using namespace std;

void plusOne(int d[]){
    int t = sizeof(*d) - 1,k = t - 1, num = 0;

    int i;
    for(i = 0; i != t; i++){
        num += d[i] * pow(10, k);
        k--;
    }

    num++;

    for(i = t - 1; i >= 0; i--){
        d[i] = num % 10;
        num /= 10;
    }

    for(i = 0; i != t; i++){
        cout << d[i] << endl;
    }
}

int main(){
    int mat[3] = {1, 2, 3};

    plusOne(mat);
}
