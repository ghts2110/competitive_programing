#include <iostream>

using namespace std;

int main(){
    int n, m, cont = 1;
    while(1){
        cin >> m >> n;

        if(m == 0 && n == 0){
            break;
        }

        int array[m][n], new_array[m][n];

        for(int i = 0; i != m; i++){
            for(int j = 0; j != n; j++){
                cin >> array[i][j];
            }
        }

        int x, y, indexX = 0, indexY = 0;
        while(1){
            cin >> x >> y;
            if(x == 0 && y == 0){
                break;
            }

            indexX += x;
            indexY -= y;

            while(indexX <= -1){
                indexX += n;
            }
            while(indexX >= n){
                indexX -= n;
            }

            while(indexY <= -1){
                indexY += m;
            }
            while(indexY >= m){
                indexY -= m;
            }
        }

        for(int i = 0; i != m; i++){
            for(int j = 0; j != n; j++){
                new_array[indexY][indexX] = array[i][j];
                indexX++;
                if(indexX == n){
                   indexX = 0;
                }
            }
            indexY++;
        
            if(indexY == m){
                indexY = 0;
            }
        }

        cout << "Teste " << cont << endl;
        for(int i = 0; i != m; i++){
            for(int j = 0; j != n; j++){
                if(j == n-1){
                    cout << new_array[i][j] << endl;
                    break;
                }
                cout << new_array[i][j] << " ";
            }
        }

        cont++;
        cout << endl;
    }
}
