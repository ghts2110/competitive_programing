#include <iostream>

using namespace std;

int main(){
    int n, m;
    while(cin >> n >> m){

        int cont = 0;
        for(int i = 0; i != n; i++){
            int sum = 0;
            for(int j = 0; j != m; j++){
                int num;
                cin >> num;

                if(num != 0){
                    sum++;
                }
            }

            if(sum == m){
                cont++;
            }
        }

        cout << cont << endl;
    }
}
