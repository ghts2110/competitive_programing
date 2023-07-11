#include <iostream> 

using namespace std;

int main(){
    int n, k;
    
    cin >> n >> k;

    while(k != 0 && n != 0){
        if(n % 10 > k){
            n -= k;
            break;
        }

        k -= n % 10;
        n -= n % 10;


        if(k == 0){
            break;
        }

        n /= 10;
        k--;
    }
    
    cout << n << endl;
}
