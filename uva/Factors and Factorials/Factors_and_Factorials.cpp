#include <iostream>
#include <map>
#include <vector>

using namespace std;
int rry[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};

void phi(int x, vector<int> &v){
    int ind = 0;
    while(x != 1){
        while(x%rry[ind] == 0){
            v[ind]++;
            x/=rry[ind];
        }
        ind++;
    }
}

int main(){
    vector<vector<int>> v(101, vector<int>(25));
    for(int i = 2; i <= 100; i++){
        for(int j = 0; j != 25; j++){
            v[i][j] = v[i-1][j];
        }
        phi(i, v[i]);
    }
    int n;   
    while(cin >> n){
        if(n == 0){
            break;
        }

        bool f = true;
        vector<int> save;
        for(int i = v[n].size()-1; i != -1; i--){
            if(v[n][i] != 0){
                f = false;
            }

            if(f){
                continue;
            }

            save.push_back(v[n][i]);
        }

        printf("%3d! =", n);
        int cont = 0;
        for(int i = save.size()-1; i != -1; i--){
            if(cont%15==0 && cont != 0){
                printf("\n%9d", save[i]);
                cont++;
                continue;
            }
            cont++;
            printf("%3d", save[i]);
        }
        printf("\n");
    }
}
