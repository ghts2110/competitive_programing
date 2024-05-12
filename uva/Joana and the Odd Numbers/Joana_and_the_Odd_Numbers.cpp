#include <iostream>

using namespace std;

int main(){
    long long n;
    while(cin >> n){
        long long n_odd = n/2+1;
        long long sum = (n+1) * (n_odd/2);

        if(n_odd%2==1){
            sum += n_odd; 
        }

        sum *= 2;
        sum--;

        long long asw = 0;
        asw += sum;
        sum -= 2;
        asw += sum;
        sum -= 2;
        asw += sum;

        cout << asw << endl;
    }
}
