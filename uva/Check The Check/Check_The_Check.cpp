#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    vector<vector<char>> v(8, vector<char> (8));
    string s;

    int test = 1;
    while(cin >> s){
        int validate = true;
        for(int i = 0; i != 8; i++){
            if(i != 0){
                cin >> s;
            }

            for(int j = 0; j != 8; j++){
                if(s[j] == '.'){
                    v[i][j] = '.';
                }else{
                    validate = false;
                    v[i][j] = s[j];
                }
            }
        }

        if(validate){
            break;
        }

        bool w = false, b = false;
        for(int i = 0; i != 8; i++){
            for(int j = 0; j != 8; j++){
                if(v[i][j] == 'r'){
                    for(int k = j+1; k != 8; k++){
                        if(v[i][k] == 'K'){
                            w = true;
                            break;
                        }else if(v[i][k] != '.'){
                            break;
                        }
                    }    
                    for(int k = j-1; k != -1; k--){
                        if(v[i][k] == 'K'){
                            w = true;
                            break;
                        }else if(v[i][k] != '.'){
                            break;
                        } 
                    }
                    for(int k = i+1; k != 8; k++){
                        if(v[k][j] == 'K'){
                            w = true;
                            break;
                        }else if(v[k][j] != '.'){
                            break;
                        }
                    }
                    for(int k = i-1; k != -1; k--){
                        if(v[k][j] == 'K'){
                            w = true;
                            break;
                        }else if(v[k][j] != '.'){
                            break;
                        }
                    }
                }else if(v[i][j] == 'R'){
                    for(int k = j+1; k != 8; k++){
                        if(v[i][k] == 'k'){
                            b = true;
                            break;
                        }else if(v[i][k] != '.'){
                            break;
                        }
                    }    
                    for(int k = j-1; k != -1; k--){
                        if(v[i][k] == 'k'){
                            b = true;
                            break;
                        }else if(v[i][k] != '.'){
                            break;
                        } 
                    }
                    for(int k = i+1; k != 8; k++){
                        if(v[k][j] == 'k'){
                            b = true;
                            break;
                        }else if(v[k][j] != '.'){
                            break;
                        }
                    }
                    for(int k = i-1; k != -1; k--){
                        if(v[k][j] == 'k'){
                            b = true;
                            break;
                        }else if(v[k][j] != '.'){
                            break;
                        }
                    }
                }else if(v[i][j] == 'n'){
                    if(j+2 < 8){
                        if(i-1 > -1 && v[i-1][j+2] == 'K'){
                            w = true;
                        }
                        if(i+1 < 8 && v[i+1][j+2] == 'K'){
                            w = true;
                        }
                    }
                    if(j-2 > -1){
                        if(i-1 > -1 && v[i-1][j-2] == 'K'){
                            w = true;
                        }
                        if(i+1 < 8 && v[i+1][j-2] == 'K'){
                            w = true;
                        }
                    }
                    if(i+2 < 8){
                        if(j+1 < 8 && v[i+2][j+1] == 'K'){
                            w = true;
                        }
                        if(j-1 > -1 && v[i+2][j-1] == 'K'){
                            w = true;
                        }
                    }
                    if(i-2 > -1){
                        if(j+1 < 8 && v[i-2][j+1] == 'K'){
                            w = true; 
                        }
                        if(j-1 > -1 && v[i-2][j-1] == 'K'){
                            w = true;
                        }
                    }
                }else if(v[i][j] == 'N'){
                    if(j+2 < 8){
                        if(i-1 > -1 && v[i-1][j+2] == 'k'){
                            b = true;
                        }
                        if(i+1 < 8 && v[i+1][j+2] == 'k'){
                            b = true;
                        }
                    }
                    if(j-2 > -1){
                        if(i-1 > -1 && v[i-1][j-2] == 'k'){
                            b = true;
                        }
                        if(i+1 < 8 && v[i+1][j-2] == 'k'){
                            b = true;
                        }
                    }
                    if(i+2 < 8){
                        if(j+1 < 8 && v[i+2][j+1] == 'k'){
                            b = true;
                        }
                        if(j-1 > -1 && v[i+2][j-1] == 'k'){
                            b = true;
                        }
                    }
                    if(i-2 > -1){
                        if(j+1 < 8 && v[i-2][j+1] == 'k'){
                            b = true; 
                        }
                        if(j-1 > -1 && v[i-2][j-1] == 'k'){
                            b = true;
                        }
                    }
                }else if(v[i][j] == 'b'){
                    for(int k = 1; k != 8; k++){
                        if(i+k < 8 && j+k < 8 && v[i+k][j+k] == 'K'){
                            w = true;
                            break;
                        }
                        if(i+k >= 8 || j+k >=8 || v[i+k][j+k] != '.'){
                            break;
                        }
                    }
                    for(int k = 1; k != 8; k++){
                        if(!(i+k >= 8 || j-k <=-1) && v[i+k][j-k] == 'K'){
                            w = true;
                            break;
                        }
                        if(i+k >= 8 || j-k <=-1 || v[i+k][j-k] != '.'){
                            break;
                        }
                    }
                    for(int k = 1; k != 8; k++){
                        if(!(i-k <=-1 || j-k <=-1) && v[i-k][j-k] =='K'){
                            w = true;
                            break;
                        }
                        if(i-k <=-1 || j-k <=-1 || v[i-k][j-k] != '.'){
                            break;
                        }
                    }
                    for(int k = 1; k != 8; k++){
                        if(!(i-k <= -1 || j+k >=8) && v[i-k][j+k] == 'K'){
                            w = true;
                            break;
                        }
                        if(i-k <= -1 || j+k >=8 || v[i-k][j+k] != '.'){
                            break;
                        }
                    }
                }else if(v[i][j] == 'B'){
                    for(int k = 1; k != 8; k++){
                        if(i+k < 8 && j+k < 8 && v[i+k][j+k] == 'k'){
                            b = true;
                            break;
                        }
                        if(i+k >= 8 || j+k >=8 || v[i+k][j+k] != '.'){
                            break;
                        }
                    }
                    for(int k = 1; k != 8; k++){
                        if(!(i+k >= 8 || j-k <=-1) && v[i+k][j-k] == 'k'){
                            b = true;
                            break;
                        }
                        if(i+k >= 8 || j-k <=-1 || v[i+k][j-k] != '.'){
                            break;
                        }
                    }
                    for(int k = 1; k != 8; k++){
                        if(!(i-k <=-1 || j-k <=-1) && v[i-k][j-k] =='k'){
                            b = true;
                            break;
                        }
                        if(i-k <=-1 || j-k <=-1 || v[i-k][j-k] != '.'){
                            break;
                        }
                    }
                    for(int k = 1; k != 8; k++){
                        if(!(i-k <= -1 || j+k >=8) && v[i-k][j+k] == 'k'){
                            b = true;
                            break;
                        }
                        if(i-k <= -1 || j+k >=8 || v[i-k][j+k] != '.'){
                            break;
                        }
                    }
                }else if(v[i][j] == 'q'){
                    for(int k = j+1; k != 8; k++){
                        if(v[i][k] == 'K'){
                            w = true;
                            break;
                        }else if(v[i][k] != '.'){
                            break;
                        }
                    }    
                    for(int k = j-1; k != -1; k--){
                        if(v[i][k] == 'K'){
                            w = true;
                            break;
                        }else if(v[i][k] != '.'){
                            break;
                        } 
                    }
                    for(int k = i+1; k != 8; k++){
                        if(v[k][j] == 'K'){
                            w = true;
                            break;
                        }else if(v[k][j] != '.'){
                            break;
                        }
                    }
                    for(int k = i-1; k != -1; k--){
                        if(v[k][j] == 'K'){
                            w = true;
                            break;
                        }else if(v[k][j] != '.'){
                            break;
                        }
                    }

                    for(int k = 1; k != 8; k++){
                        if(i+k < 8 && j+k < 8 && v[i+k][j+k] == 'K'){
                            w = true;
                            break;
                        }
                        if(i+k >= 8 || j+k >=8 || v[i+k][j+k] != '.'){
                            break;
                        }
                    }
                    for(int k = 1; k != 8; k++){
                        if(!(i+k >= 8 || j-k <=-1) && v[i+k][j-k] == 'K'){
                            w = true;
                            break;
                        }
                        if(i+k >= 8 || j-k <=-1 || v[i+k][j-k] != '.'){
                            break;
                        }
                    }
                    for(int k = 1; k != 8; k++){
                        if(!(i-k <=-1 || j-k <=-1) && v[i-k][j-k] =='K'){
                            w = true;
                            break;
                        }
                        if(i-k <=-1 || j-k <=-1 || v[i-k][j-k] != '.'){
                            break;
                        }
                    }
                    for(int k = 1; k != 8; k++){
                        if(!(i-k <= -1 || j+k >=8) && v[i-k][j+k] == 'K'){
                            w = true;
                            break;
                        }
                        if(i-k <= -1 || j+k >=8 || v[i-k][j+k] != '.'){
                            break;
                        }
                    }
                }else if(v[i][j] == 'Q'){
                    for(int k = j+1; k != 8; k++){
                        if(v[i][k] == 'k'){
                            b = true;
                            break;
                        }else if(v[i][k] != '.'){
                            break;
                        }
                    }    
                    for(int k = j-1; k != -1; k--){
                        if(v[i][k] == 'k'){
                            b = true;
                            break;
                        }else if(v[i][k] != '.'){
                            break;
                        } 
                    }
                    for(int k = i+1; k != 8; k++){
                        if(v[k][j] == 'k'){
                            b = true;
                            break;
                        }else if(v[k][j] != '.'){
                            break;
                        }
                    }
                    for(int k = i-1; k != -1; k--){
                        if(v[k][j] == 'k'){
                            b = true;
                            break;
                        }else if(v[k][j] != '.'){
                            break;
                        }
                    }

                    for(int k = 1; k != 8; k++){
                        if(i+k < 8 && j+k < 8 && v[i+k][j+k] == 'k'){
                            b = true;
                            break;
                        }
                        if(i+k >= 8 || j+k >=8 || v[i+k][j+k] != '.'){
                            break;
                        }
                    }
                    for(int k = 1; k != 8; k++){
                        if(!(i+k >= 8 || j-k <=-1) && v[i+k][j-k] == 'k'){
                            b = true;
                            break;
                        }
                        if(i+k >= 8 || j-k <=-1 || v[i+k][j-k] != '.'){
                            break;
                        }
                    }
                    for(int k = 1; k != 8; k++){
                        if(!(i-k <=-1 || j-k <=-1) && v[i-k][j-k] =='k'){
                            b = true;
                            break;
                        }
                        if(i-k <=-1 || j-k <=-1 || v[i-k][j-k] != '.'){
                            break;
                        }
                    }
                    for(int k = 1; k != 8; k++){
                        if(!(i-k <= -1 || j+k >=8) && v[i-k][j+k] == 'k'){
                            b = true;
                            break;
                        }
                        if(i-k <= -1 || j+k >=8 || v[i-k][j+k] != '.'){
                            break;
                        }
                    }
                }else if(v[i][j] == 'p'){
                    if(i+1 < 8 && j-1 > -1 && v[i+1][j-1] == 'K'){
                        w = true;
                    }
                    if(i+1 < 8 && j+1 < 8 && v[i+1][j+1] == 'K'){
                        w = true;
                    }
                }else if(v[i][j] == 'P'){
                    if(i-1 > -1 && j-1 > -1 && v[i-1][j-1] == 'k'){
                        b = true;
                    }
                    if(i-1 > -1 && j+1 < 8 && v[i-1][j+1] == 'k'){
                        b = true;
                    }
                }
            } 
        }

        cout << "Game #"<<test<<":";
        test++;
        if((w && b) || (!w && !b)){
            cout << " no king is in check." << endl;
        }else if(w){
            cout << " white king is in check." << endl;
        }else if(b){
            cout << " black king is in check." << endl;
        }
    }
}
