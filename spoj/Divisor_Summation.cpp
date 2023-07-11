#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int t;
    cin >> t;
    
    while(t--){
        long long num, sum = 0;
        cin >> num;

        if(num == 1){
            cout << 0 << endl;
            continue;
        }

        for(int i = 1; i <= sqrt(num); i++){
            if(num % i == 0){
                sum += i;
                if(i != num/i){
                    sum += (num/i);
                }
            }
        }
        sum -= num;

        cout << sum << endl;
    }
}
