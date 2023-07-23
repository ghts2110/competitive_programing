#include <iostream>

using namespace std;

int main(){
    double t;
    cin >> t;

    double sum = 0;
    for(int i = 0; i != t; i++){
        int num;
        cin >> num;

        if(num == -1){
            t--;
            i--;
            continue;
        }

        sum += num;
    }

    printf("%.3f\n", sum/t);
}
