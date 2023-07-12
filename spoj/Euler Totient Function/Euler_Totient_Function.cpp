#include <iostream>

using namespace std;

int phi(int num){
    float value = num; 

    for(int i = 2; i * i <= num; i++){
        if(num % i == 0){
            while(num % i == 0){
                num /= i;
            }

            value *= 1.0 - (1.0/(float)i);
        }
    }

    if(num > 1){
         value -= value / num;
    }

    return (int)value;;
}

int main(){
    int t; 
    cin >> t;

    while(t--){
        int num;
        cin >> num;
    
        cout << phi(num) << endl;
    }
}
