#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    string s;
    while(cin >> s){
        vector<vector<int>> v(8, vector<int> (8));
        int l = 0, c = 0;
        for(char i : s){
            if((i >= 'a' && i <= 'z')||(i >= 'A' && i <= 'Z')){
                v[l][c] = 2;
                c++;
                continue;
            }
            if(i == '/'){
                c = 0;
                l++;
                continue;
            }
            c += i - '0';
        }

        c = l = 0;
        for(char i : s){
            if(i == '/'){
                c = 0;
                l++;
                continue;
            }
            
            if(i == 'p'){   
                if(l+1 < 8 && c-1 > -1 && v[l+1][c-1] != 2){
                    v[l+1][c-1] = 1;
                }
                if(l+1 < 8 && c+1 < 8 && v[l+1][c+1] != 2){
                    v[l+1][c+1] = 1;
                }
                c++;
            }else if(i == 'P'){
                if(l-1 > -1 && c-1 > -1 && v[l-1][c-1] != 2){
                    v[l-1][c-1] = 1;
                }
                if(l-1 > -1 && c+1 < 8 && v[l-1][c+1] != 2){
                    v[l-1][c+1] = 1;
                }
                c++;
            }else if(i == 'r' || i == 'R'){
                for(int j = c+1; j != 8; j++){
                    if(v[l][j] == 2){
                        break;
                    } 
                    v[l][j] = 1;
                }
                for(int j = c-1; j != -1; j--){
                    if(v[l][j] == 2){
                        break;
                    }
                    v[l][j] = 1;
                }
                for(int j = l+1; j != 8; j++){
                    if(v[j][c] == 2){
                        break;
                    }
                    v[j][c] = 1;
                }
                for(int j = l-1; j != -1; j--){
                    if(v[j][c] == 2){
                        break;
                    }
                    v[j][c] = 1;
                }
                c++;
            }else if(i == 'q' || i == 'Q'){
                for(int j = c+1; j != 8; j++){
                    if(v[l][j] == 2){
                        break;
                    } 
                    v[l][j] = 1;
                }
                for(int j = c-1; j != -1; j--){
                    if(v[l][j] == 2){
                        break;
                    }
                    v[l][j] = 1;
                }
                for(int j = l+1; j != 8; j++){
                    if(v[j][c] == 2){
                        break;
                    }
                    v[j][c] = 1;
                }
                for(int j = l-1; j != -1; j--){
                    if(v[j][c] == 2){
                        break;
                    }
                    v[j][c] = 1;
                }
                for(int j = 1; j != 8; j++){
                    if(l+j >= 8 || c+j >=8 || v[l+j][c+j] == 2){
                        break;
                    }
                    v[l+j][c+j] = 1;
                }
                for(int j = 1; j != 8; j++){
                    if(l+j >= 8 || c-j <=-1 || v[l+j][c-j] == 2){
                        break;
                    }
                    v[l+j][c-j] = 1;
                }
                for(int j = 1; j != 8; j++){
                    if(l-j <=-1 || c-j <=-1 || v[l-j][c-j] == 2){
                        break;
                    }
                    v[l-j][c-j] = 1;
                }
                for(int j = 1; j != 8; j++){
                    if(l-j <= -1 || c+j >=8 || v[l-j][c+j] == 2){
                        break;
                    }
                    v[l-j][c+j] = 1;
                }

                c++;
            }else if(i == 'n' || i == 'N'){
                if(c+2 < 8){
                    if(l-1 > -1 && v[l-1][c+2] != 2){
                        v[l-1][c+2] = 1;
                    }
                    if(l+1 < 8 && v[l+1][c+2] != 2){
                        v[l+1][c+2] = 1;
                    }
                } 
                if(c-2 > -1){
                    if(l-1 > -1 && v[l-1][c-2] != 2){
                        v[l-1][c-2] = 1;
                    }
                    if(l+1 < 8 && v[l+1][c-2] != 2){
                        v[l+1][c-2] = 1;
                    }
                }
                if(l+2 < 8){
                    if(c+1 < 8 && v[l+2][c+1] != 2){
                        v[l+2][c+1] = 1;
                    }
                    if(c-1 > -1 && v[l+2][c-1] != 2){
                        v[l+2][c-1] = 1;
                    }
                }
                if(l-2 > -1){
                    if(c+1 < 8 && v[l-2][c+1] != 2){
                        v[l-2][c+1] = 1;
                    }
                    if(c-1 > -1 && v[l-2][c-1] != 2){
                        v[l-2][c-1] = 1;
                    }
                }
                c++;
            }else if(i == 'b' || i == 'B'){
                 for(int j = 1; j != 8; j++){
                    if(l+j >= 8 || c+j >=8 || v[l+j][c+j] == 2){
                        break;
                    }
                    v[l+j][c+j] = 1;
                }
                for(int j = 1; j != 8; j++){
                    if(l+j >= 8 || c-j <=-1 || v[l+j][c-j] == 2){
                        break;
                    }
                    v[l+j][c-j] = 1;
                }
                for(int j = 1; j != 8; j++){
                    if(l-j <=-1 || c-j <=-1 || v[l-j][c-j] == 2){
                        break;
                    }
                    v[l-j][c-j] = 1;
                }
                for(int j = 1; j != 8; j++){
                    if(l-j <= -1 || c+j >=8 || v[l-j][c+j] == 2){
                        break;
                    }
                    v[l-j][c+j] = 1;
                }
                c++;
            }else if(i == 'k' || i == 'K'){
                if(c-1 > -1 && v[l][c-1] != 2){
                    v[l][c-1] = 1;
                } 
                if(c+1 < 8 && v[l][c+1] != 2){
                    v[l][c+1] = 1;
                }
                if(l-1 > -1 && v[l-1][c] != 2){
                    v[l-1][c] = 1;
                }
                if(l+1 < 8 && v[l+1][c] != 2){
                    v[l+1][c] = 1;
                }
                if(c-1 > -1 && l-1 > -1 && v[l-1][c-1] != 2){
                    v[l-1][c-1] = 1;
                }
                if(c-1 > -1 && l+1 < 8 && v[l+1][c-1] != 2){
                    v[l+1][c-1] = 1;
                }
                if(c+1 < 8 && l+1 < 8 && v[l+1][c+1] != 2){
                    v[l+1][c+1] = 1;
                }
                if(c+1 < 8 && l-1 > -1 && v[l-1][c+1] != 2){
                    v[l-1][c+1] = 1;
                }
                c++;
            }else{
                c += i - '0';
            }


        }

        int cont = 0;
        for(int i = 0; i != 8; i++){
            for(int j = 0; j != 8; j++){
                if(v[i][j] == 0){
                    cont++;
                }
            }
        }
        cout << cont << endl;
    }
}
