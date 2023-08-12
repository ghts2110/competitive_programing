#include <iostream>

using namespace std;

int gcd(int a, int b){
    if(b == 0){
        return a;
    }

    return gcd(b, a%b);
}

int main(){
    int n;
    while(cin >> n){
        if(n == 0){
            break;
        }

        long long g = 0;
        for(int i = 1; i != n; i++){
            for(int j = i+1; j <= n; j++){
                g+= gcd(i, j);
            }
        }

        cout << g << endl;
    }
}
