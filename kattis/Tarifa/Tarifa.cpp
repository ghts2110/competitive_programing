#include <iostream>

using namespace std;

int main(){
    int x, n;

    cin >> x >> n;

    int cont = 0;
    for(int i = 0; i != n; i++){
        int num;
        cin >> num;

        cont += x - num;
    }

    cont += x;

    cout << cont << endl;
}
