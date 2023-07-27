#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int n, i, j;
    while(cin >> n >> i >> j){
        int cont = n, s = 0, e = pow(2, n);
        while(cont != 1){
            int mid = (s+e)/2;

            if((i <= mid && mid < j) || (j <= mid && mid < i)){
                break;
            }

            if(mid < j){
                s = mid;
            }else{
                e = mid;
            }
            cont--;
        }

        cout << cont << endl;

    }
}
