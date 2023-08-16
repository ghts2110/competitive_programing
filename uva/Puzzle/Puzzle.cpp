#include <iostream>
#include <vector>
#include <string>

#define pb push_back

using namespace std;

int main(){
    int test = 1;
        
    string s;
    while(getline(cin, s)){
        if(test != 1){
            getline(cin, s);
        }
        if(s == "Z"){
            break;
        }

        vector<string> v;
        int x, y;

        for(int i = 0; i != 5; i++){
            if(i != 0){
                getline(cin, s);
            }
            v.pb(s);
            for(int j = 0; j != 5; j++){
                if(v[i].size() == 4){
                    v[i].pb(' ');
                    x = i;
                    y = 4;
                    break;
                }
                if(v[i][j] == ' '){
                    x = i;
                    y = j;
                    break;
                }
            }
        }

        bool validate = true;
        while(1){  
            char c;
            cin >> c;
            if(c == '0'){
                break;
            }

            if(c == 'A'){
                if(x-1 >= 0){
                    v[x][y] = v[x-1][y];
                    v[x-1][y] = ' ';
                    x--;
                }else{
                    validate = false;
                }
            }else if(c == 'R'){
                if(y+1 < 5){
                    v[x][y] = v[x][y+1];
                    v[x][y+1] = ' ';
                    y++;
                }else{
                    validate = false;
                }
            }else if(c == 'L'){
                if(y-1 >= 0){
                    v[x][y] = v[x][y-1];
                    v[x][y-1] = ' ';
                    y--;
                }else{
                    validate = false;
                }
            }else if(c == 'B'){
                if(x+1 < 5){
                    v[x][y] = v[x+1][y];
                    v[x+1][y] = ' ';
                    x++;
                }else{
                    validate = false;
                }
            }else{
                validate = false;
            }
        }

        if(test != 1){
            cout << endl;
        }
        cout << "Puzzle #"<<test<<":" << endl;
        test++;

        if(validate){
            for(int i = 0; i != 5; i++){
                for(int j = 0; j != 5; j++){
                    if(j == 4){
                        cout << v[i][j] << endl;
                        break;
                    }
                    cout << v[i][j] << " ";
                }
            }
        }else{  
            cout << "This puzzle has no final configuration." << endl;
        }
    }
}
