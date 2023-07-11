#include <iostream>
#include <bitset>

using namespace std;

int main(){
    int n, b;
    while(1){
        cin >> n >> b;

        if(n == 0 && b == 0){
            break;
        }

        int array[b], cont = 0;
        bitset<91> bt(0);

        for(int i = 0; i != b; i++){
            cin >> array[i];

            for(int j = 0; j <= i; j++){

                if(bt[abs(array[i] - array[j])] == 0){
                    cont++;
                    bt[abs(array[i] - array[j])] = 1;
                }
            }
        }

        if(cont == n+1){
            cout << "Y" << endl;
        }else{
            cout << "N" << endl;
        }

    }
}
