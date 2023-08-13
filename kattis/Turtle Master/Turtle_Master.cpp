#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    vector<string> v(8);

    int d1, d2;
    for(int i = 0; i != 8; i++){
        cin >> v[i];
        for(int j = 0; j != 8; j++){
            if(v[i][j] == 'D'){
               d1 = i;
               d2 = j;
               v[i][j] = '.';
            }
        }
    }

    string s;
    cin >> s;

    char l = 'r';

    bool validate = false;
    int x = 7, y = 0;

    for(int i = 0; i != s.size(); i++){
        if(s[i] == 'F'){
            if(l == 'r'){
                if(y+1 < 8 && v[x][y+1] == '.'){
                    v[x][y+1] = 'T';
                    v[x][y] = '.';
                    y++;
                }else{
                    break;
                }
            }else if(l == 'l'){
                if(y-1 > -1 && v[x][y-1] == '.'){
                    v[x][y-1] = 'T';
                    v[x][y] = '.';
                    y--;
                }else{
                    break;
                }
            }else if(l == 't'){
                if(x-1 > -1 && v[x-1][y] == '.'){
                    v[x-1][y] = 'T';
                    v[x][y] = '.';
                    x--;
                }else{
                    break;
                }
            }else{
                if(x+1 < 8 && v[x+1][y] == '.'){
                    v[x+1][y] = 'T';
                    v[x][y] = '.';
                    x++;
                }else{
                    break;
                }
            }
        }else if(s[i] == 'L'){
            if(l == 'r'){
                l = 't';
            }else if(l == 't'){
                l = 'l';
            }else if(l == 'l'){
                l = 'd';
            }else{
                l = 'r';
            }
        }else if(s[i] == 'R'){
            if(l == 'r'){
                l = 'd';
            }else if(l == 't'){
                l = 'r';
            }else if(l == 'l'){
                l = 't';
            }else{
                l = 'l';
            }
        }else{
            if(l == 'r'){
                if(y+1 < 8 && v[x][y+1] == 'I'){
                    v[x][y+1] = '.';
                }else if(!(x == d1 && y+1 == d2)){
                    break;
                }
            }else if(l == 'l'){
                if(y-1 > -1 && v[x][y-1] == 'I'){
                    v[x][y-1] = '.';
                }else if(!(x == d1 && y-1 == d2)){
                    break;
                }
            }else if(l == 't'){
                if(x-1 > -1 && v[x-1][y] == 'I'){
                    v[x-1][y] = '.';
                }else if(!(x-1 == d1 && y == d2)){
                    break;
                }
            }else{
                if(x+1 < 8 && v[x+1][y] == 'I'){
                    v[x+1][y] = '.';
                }else if(!(x+1 == d1 && y == d2)){
                    break;
                }
            }
        }
    }

    if(d1 == x && d2 == y){
        validate = true;
    }

    if(validate){
        cout << "Diamond!" << endl;
    }else{
        cout << "Bug!" << endl;
    }
}
