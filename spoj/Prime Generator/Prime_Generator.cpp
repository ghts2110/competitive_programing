#include <iostream>
#include <cmath>

using namespace std;

bool is_prime(int num){
    if(num == 1){
        return false;
    }

    for(int i = 2; i <= sqrt(num); i++){
        if(num % i == 0){
            return false;
        }
    }

    return true;
}

int main(){
    int t;
    cin >> t;
    bool isfirst = true;

    while(t--){
        if(isfirst){
            isfirst = false;
        }else{
            cout << endl;
        }
        int n, m;
        cin >> n >> m;

        for(int i = n; i <=m; i++){
            if(is_prime(i)){
                cout << i << endl;
            }
        }
    }
}
