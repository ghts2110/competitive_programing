#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int n, r, k;
    cin >> n >> r >> k;

    int cont = max(n, k + abs(r-k)) + r;
    if(n%2 != r%2 && n > k + abs(k-r)){
        cont++;
    }
    cout << cont << endl;
}
