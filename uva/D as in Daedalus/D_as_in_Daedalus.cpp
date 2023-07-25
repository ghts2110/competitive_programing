#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int n, m;
    while(cin >> n >> m){
        int b;
        
        int value = 0;
        for(int i = 0; i != m; i++){
            cin >> b;
            int cont = 0, save;
            
            for(int j = 0; j != n; j++){
                int num;
                cin >> num;

                if(j == 0){
                    save = num;
                    continue;
                }

                cont += num;
            }

            if(b < cont){
                continue;
            }


            b -= cont;
            int j = 0;
            while(b != 0){
                j++;
                b/=10;
                if(j == 5){
                    break;
                }
            }
        
            int pw = pow(10, j-1);
            if(save == pw){
                continue;
            }else if(save <= pw){
                value += pw-save;
            }else{
                value += pw;
            }

        }

        cout << value << endl;
    }
}
