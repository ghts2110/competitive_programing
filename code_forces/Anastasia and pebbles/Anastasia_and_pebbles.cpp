#include <iostream>

using namespace std;

int main(){
    int n, k, day = 0, div = 0;
    cin >> n >> k;


    while(n--){
        int num;
        cin >> num;
        num -= div;
        div = 0;

        day += num / (2*k);
        num %= 2*k;

        if(num <= k && num > 0){
            div = k;
            day++;
        }else if(num > 0){
            day++;
        }
    }
 
    cout << day << endl;
}
