#include <iostream>
#include <vector>

using namespace std;
vector<vector<int> > mat;

int cnt(int v, int i, int j){
    int cont = 0;
    

    if(mat[i][j] == v){
        mat[i][j] = -1;
        cont++;
        
        if(j < mat[i].size() - 1){
            cont += cnt(v, i, j + 1);
        }
        if(j > 0){
            cont += cnt(v, i, j - 1);
        }
        if(i > 0){
            cont += cnt(v, i - 1, j);
        }
        if(i < mat.size() - 1){
            cont += cnt(v, i + 1, j);
        }

       
    }else{
        return 0;
    }

    return cont;
} 

int main(){
    int x, y, n;
    cin >> y >> x;
    vector<int> array;

    int i, j;
    for(i = 0; i != y; i++){
        mat.push_back(array);
        for(j = 0; j != x; j++){
            cin >> n;
            mat[i].push_back(n);
        }
    }

    int cont = 0, min = 40000;
    for(i = 0; i != y; i++){
        for(j = 0; j != x; j++){
            int v = mat[i][j];
            if(v != -1){
                cont = cnt(v, i, j);
                if(cont < min){
                    min = cont;
                }
            }
        }
    }

    cout << min << endl;
}
