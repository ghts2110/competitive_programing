#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    int linhas,colunas;
    int test = 1;
    int fist = 1;

    while(1 ){
        cin >> linhas >> colunas;

        if(linhas == 0 && colunas == 0){
            break;
        }

        if(fist == 0){
            cout << endl;
        }
        vector<vector<char> > matriz;
        matriz.resize(linhas);
        for(int i = 0; i < linhas; i++){
            for(int j = 0; j < colunas; j++){
                char c ;
                cin >> c;
                matriz[i].push_back(c);
            }
        }
        
        int cont = 0;
        vector<vector<char> > v(linhas);
        for(int i = 0; i < linhas; i++){
            for(int j = 0; j < colunas; j++){
                cont = 0;
                if(matriz[i][j] == '*'){
                    v[i].push_back('*'); 
                    continue;
                }

                if(j - 1 != -1 && matriz[i][j-1] == '*'){
                    cont ++;
                }
                if(j-1 != -1 && i-1 != -1 && matriz[i-1][j-1] == '*'){
                    cont++;
                }
                if(i - 1 != -1 && matriz[i-1][j] == '*'){
                    cont++;
                }

                if(i - 1 != -1 && j + 1 != colunas && matriz[i-1][j+1] == '*'){
                    cont++;
                }
                 
                if(j + 1 != colunas && matriz[i][j+1] == '*'){
                    cont++;
                }

                if(i+1 != linhas && j+1 != colunas && matriz[i+1][j+1] == '*'){
                    cont++;
                }

                if(i+1 != linhas && matriz[i+1][j] == '*'){
                    cont++;
                }

                if(i+1 != linhas && j-1 != -1 && matriz[i+1][j-1] == '*'){
                    cont++;
                }

                v[i].push_back(to_string(cont)[0]);
                
            }
        }

        printf("Field #%d:\n", test);
        test++;
        for(int i = 0; i != linhas; i++){
            for(int j = 0; j != colunas; j++){
                cout << v[i][j];
            }
            cout << endl;
        }
        fist = 0;
    }
    
    return 0;
}
