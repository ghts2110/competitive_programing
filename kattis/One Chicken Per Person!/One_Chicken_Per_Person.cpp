#include <iostream>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;

    if(n < m){
        if(m-n == 1){
            printf("Dr. Chaz will have %d piece of chicken left over!\n", m-n);
            return 0;
        }
        printf("Dr. Chaz will have %d pieces of chicken left over!\n", m-n);
    }else{
        if(n - m == 1){
             printf("Dr. Chaz needs %d more piece of chicken!\n", n - m);
             return 0;
        }
        printf("Dr. Chaz needs %d more pieces of chicken!\n", n - m);
    }
}
