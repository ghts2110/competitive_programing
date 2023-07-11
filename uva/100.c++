#include <iostream>

using namespace std;

int main(){
    int i, j, min, max;

    while(cin >> i){
        cin >> j;    

        if(i > j){
            max = i;
            min = j;
        }else{
            max = j;
            min = i;
        }

        int n, cont = 1, v, cont_max;
        for(n = min; n != max + 1; n++){
            cont_max = 1;
            v = n;
            while(v != 1){
                if(v % 2 == 0){
                    v /= 2;
                }else{
                    v = v*3 + 1;
                }

                cont_max++;
            }

            if(cont_max > cont){
                cont = cont_max;
            }
        }
        cout << i << " " << j << " " << cont << endl;
    }
}
