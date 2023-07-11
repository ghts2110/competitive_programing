#include <iostream>
#include <bitset>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    
    int array[n][m];

    int pivo = -1, validate = 1;
    bitset<500> bt(0);

    for(int i = 0; i != n; i++){
        int line0 = 1;
        for(int j = 0; j != m; j++){
            cin >> array[i][j];
            
            if(array[i][j] != 0 && j <= pivo){
                validate = 0;
            }

            if(bt[i] == 0 && array[i][j] != 0){
                line0 = 0;
                pivo = j;
                bt[i] = 1;
            }
        }

        if(line0 == 1){
            pivo = m;
        }
    }

    if(validate == 1){
        cout << "S" << endl;
        return 0;
    }
    cout << "N" << endl;
}
