#include <iostream>
#include <vector>

using namespace std;

int main(){
    int t;
    cin >>t;

    while(t--){
        int contO = 0, contX = 0;

        vector<vector<char>> v(3, vector<char> (3));
        for(int i = 0; i != 3; i++){
            for(int j = 0; j != 3; j++){
                cin >> v[i][j];
            }
        }

        int cont = 0;
        int k = -1;
        if(v[0][0] == v[1][0] && v[0][0] == v[2][0] && v[0][0] != '.'){
            cont++;
            if(v[0][0] == 'X'){
                k = 0;
            }else{
                k = 1;
            }
        }
        if(v[0][1] == v[1][1] && v[0][1] == v[2][1]&& v[0][1] != '.'){
            cont++;
            if(v[0][1] == 'X'){
                k = 0;
            }else{
                k = 1;
            }
        }
        if(v[0][2] == v[1][2] && v[0][2] == v[2][2]&& v[0][2] != '.'){
            cont++;
            if(v[0][2] == 'X'){
                k = 0;
            }else{
                k = 1;
            }
        }
        if(v[0][0] == v[0][1] && v[0][0] == v[0][2]&& v[0][0] != '.'){
            cont++;
            if(v[0][0] == 'X'){
                k = 0;
            }else{
                k = 1;
            }
        }
        if(v[1][0] == v[1][1] && v[1][0] == v[1][2]&& v[1][0] != '.'){
            cont++;
            if(v[1][0] == 'X'){
                k = 0;
            }else{
                k = 1;
            }
        }
        if(v[2][0] == v[2][1] && v[2][0] == v[2][2]&& v[2][0] != '.'){
            cont++;
            if(v[2][0] == 'X'){
                k = 0;
            }else{
                k = 1;
            }
        }
        if(v[0][0] == v[1][1] && v[0][0] == v[2][2]&& v[0][0] != '.'){
            cont++;
            if(v[0][0] == 'X'){
                k = 0;
            }else{
                k = 1;
            }
        }
        if(v[0][2] == v[1][1] && v[0][2] == v[2][0]&& v[0][2] != '.'){
            cont++;
            if(v[0][2] == 'X'){
                k = 0;
            }else{
                k = 1;
            }
        }

        if(cont > 1){
            if(cont == 2 && k == 0){

            }else{
                cout << "no" << endl;
                continue;
            }
        }

        for(int i = 0; i != 3; i++){
            for(char c : v[i]){
                if(c == 'X'){
                    contX++;
                }else if(c == 'O'){
                    contO++;
                }
            }
        }

        if(k == 0 && contX-1 == contO){
            cout << "yes" << endl;
        }else if(k == 1 && contX == contO){
            cout << "yes" << endl;
        }else if(k == -1 && (contX-1 == contO || contX == contO)){
            cout << "yes" << endl;
        }else{
            cout << "no" << endl;
        }


    }

}
