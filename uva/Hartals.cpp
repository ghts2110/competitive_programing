#include <iostream>
#include <bitset>

using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        int day;
        cin >> day;
    
        int p;
        cin >> p;

        bitset<3651> bt(0);

        while(p--){
            int num;
            cin >> num;

            int cont = num;
            while(cont <= day){
                if(cont % 7 != 6 && cont % 7 != 0) {
                    bt[cont] = 1;
                }

                cont += num;
            }

        }

        int cont = 0;
        for(int i = 1; i <= 3650; i++){
            if(bt[i] == 1){
                cont++;
            }
        }

        cout << cont << endl;
    }
}
