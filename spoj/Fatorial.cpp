#include <iostream>

using namespace std;

int fat(int t){
    int cont = 0;
    if(t == 0){
        return 1;
    }

    cont += t * fat(t-1);
    return cont;
}
    
int main(){
    int t;
    cin >> t;

    cout << fat(t) << endl;
}
