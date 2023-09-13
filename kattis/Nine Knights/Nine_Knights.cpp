#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    vector<string> v(5);
    int cont = 0;

    for(int i = 0; i != 5; i++){
        cin >> v[i];
        for(int j = 0; j != 5; j++){
            if(v[i][j] == 'k'){
                cont++;
            }
        }
    }

    if(cont != 9){
        cout << "invalid" << endl;
        return 0;
    }

    bool val = true;
    for(int i = 0; i != 5 && val; i++){
        for(int j = 0; j != 5 && val; j++){
            if(v[i][j] == 'k'){
                if(i-2 > -1){
                    if(j-1 > -1 && v[i-2][j-1] == 'k'){
                        val = false;
                    }
                    if(j+1 < 5 && v[i-2][j+1] == 'k'){
                        val = false;
                    }
                }
                if(i+2 < 5){
                    if(j-1 > -1 && v[i+2][j-1] == 'k'){
                        val = false;
                    }
                    if(j+1 < 5 && v[i+2][j+1] == 'k'){
                        val = false;
                    }
                }
                if(j-2 > -1){
                    if(i-1 > -1 && v[i-1][j-2] == 'k'){
                        val = false;
                    }
                    if(i+1 < 5 && v[i+1][j-2] == 'k'){
                        val = false;
                    }
                }
                if(j+2 < 5){
                    if(i-1 > -1 && v[i-1][j+2] == 'k'){
                        val = false;
                    }
                    if(i+1 < 5 && v[i+1][j+2] == 'k'){
                        val = false;
                    }
                }
            }
        }
    }

    if(val){
        cout << "valid" << endl;
    }else{
        cout << "invalid" << endl;
    }
}