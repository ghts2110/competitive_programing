#include <iostream>
#include <vector>

using namespace std;

int main(){
    while(1){
        int n, line, colum, b;
        cin >> n >> line >> colum >> b;
        if(n == 0){
            break;
        }

        vector<vector<int> > v(line), cop(line);

        for(int i = 0; i != line; i++){
            for(int j = 0; j != colum; j++){
                int num;
                cin >> num;

                v[i].push_back(num);
                cop[i].push_back(num);
            }   
        }

        for(int i = 0; i != b; i++){
            for(int j = 0; j != line; j++){
                for(int k = 0; k != colum; k++){
                    if(j -1 != -1 && (v[j][k] + 1 == v[j-1][k] || (v[j][k] == n-1 && v[j-1][k] == 0))){
                        cop[j-1][k] = v[j][k];
                    }

                    if(k + 1 != colum && (v[j][k] + 1 == v[j][k+1] || (v[j][k] == n-1 && v[j][k+1] == 0))){
                        cop[j][k+1] = v[j][k];
                    }

                    if(j+1 != line && (v[j][k] + 1 == v[j+1][k] || (v[j][k] == n-1 && v[j+1][k] == 0))){
                        cop[j+1][k] = v[j][k];
                    }

                    if(k -1 != -1 && (v[j][k] + 1 == v[j][k-1] || (v[j][k] == n-1 && v[j][k-1] == 0))){
                        cop[j][k-1] = v[j][k];
                    }
                }
            }
            v = cop;
        }


        for(int i = 0; i != line; i++){
            for(int j = 0; j != colum; j++){
                if(j == colum -1){
                    cout << v[i][j] << endl;
                    break;
                }
                cout << v[i][j] << " ";
            }
        }

    }

}
    

