#include <iostream>
#include <vector>
#include <string.h>
#include <cmath>

using namespace std;

int main(){
    int n, cont = 0, mat[5000][2]; 
    cin >> n;
    memset(mat, 0, sizeof(mat));


    while(n--){
        int m;
        char l;

        cin >> m >> l;
        if(l == 'D'){
            mat[m][0]++;
        }else{
            mat[m][1]++;
        }    
    }

    for(int i = 0; i != 5000; i++){
        cont += min(mat[i][0], mat[i][1]);
    }

    cout << cont << endl;
}
