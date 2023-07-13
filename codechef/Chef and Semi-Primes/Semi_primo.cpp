#include <iostream>
#include <cmath>

using namespace std;

bool is_primo(int num){
    for(int i = 2; i <= sqrt(num); i++){
        if(num % i == 0){
            return false;
        }
    }

    return true;
}

bool is_semi_primo(int num){
    int sp = false;
    for(int i = 2; i <= sqrt(num); i++){
        if(num % i == 0 && i != num/i && is_primo(i) && is_primo(num/i)){
            sp = true;
            break;
        }
    }

    return sp;
}

int main(){
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        int isp = 0;
        for(int i = 1; i*2 <= n; i++){
            if(is_semi_primo(i) && is_semi_primo(n-i)){
                isp = 1;
                break;
            }
        }

        if(isp == 1){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
}
