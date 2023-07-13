#include <iostream>
#include <cmath>
#include <bitset>

using namespace std;

int main(){
    int t;

    cin >> t;
    bitset<1000> bt(0);    

    if( t == 1 ){
        cout << 0 << endl;
        return 0;
    }

    int cont = 0;

    for(int k = 2; k <= t; k++){
        int p = 0;
        for(int i = 2; i < k; i++){
            if(k % i == 0){
                p = 1;
                break;
            }
        }
        
        for(int i = 1; i != 10 && p != 1; i++){
            if(pow(k, i) <= t){
                bt[pow(k,i)] = 1;
                cont++;
            }else{
                break;
            }
        }
    }

    cout << cont << endl;
    for(int i = 0; i != 1000; i++){
        if(bt[i] == 1){
            cout << i << " ";
            cont--;
        }
        if(cont == 0){
            break;
        }
    }
    cout << endl;
}
