#include <iostream>
#include <vector>
#include <set>
#include <string>

using namespace std;

void input(vector<string>& v, int x, int y, char p){
    x--;
    y--;
    v[x][y] = p;

    for(int i = x-1; i >= 0; i--){
        if(v[i][y] == '-'){
            break;
        }
        if(v[i][y] == p){
            for(int j = x; j != i; j--){
                v[j][y] = p;
            }
            break;
        }
    }

    for(int i = x+1; i < 8; i++){
        if(v[i][y] == '-'){
            break;
        }
        if(v[i][y] == p){
            for(int j = x; j != i; j++){
                v[j][y] = p;
            }
            break;
        }
    }

    for(int i = y-1; i >= 0; i--){
        if(v[x][i] == '-'){
            break;
        }
        if(v[x][i] == p){
            for(int j = y; j != i; j--){
                v[x][j] = p;
            }
            break;
        }
    }

    for(int i = y+1; i < 8; i++){
        if(v[x][i] == '-'){
            break;
        }
        if(v[x][i] == p){
            for(int j = y; j != i; j++){
                v[x][j] = p;
            }
            break;
        }
    }

    for(int i = 1; i != 8; i++){
        if(x-i < 0 || y-i < 0 || v[x-i][y-i] == '-'){
            break;
        }
        if(v[x-i][y-i] == p){
            for(int j = 1; j != i; j++){
                v[x-j][y-j] = p;
            }
            break;
        }
    }

    for(int i = 1; i != 8; i++){
        if(x+i >= 8 || y+i >= 8 || v[x+i][y+i] == '-'){
            break;
        }
        if(v[x+i][y+i] == p){
            for(int j = 1; j != i; j++){
                v[x+j][y+j] = p;
            }
            break;
        }
    }

    for(int i = 1; i != 8; i++){
        if(x-i < 0 || y+i >= 8 || v[x-i][y+i] == '-'){
            break;
        }
        if(v[x-i][y+i] == p){
            for(int j = 1; j != i; j++){
                v[x-j][y+j] = p;
            }
            break;
        }
    }

    for(int i = 1; i != 8; i++){
        if(x+i >= 8 || y-i < 0 || v[x+i][y-i] == '-'){
            break;
        }
        if(v[x+i][y-i] == p){
            for(int j = 1; j != i; j++){
                v[x+j][y-j] = p;
            }
            break;
        }
    }

}

void contar(vector<string> v){
    int contW = 0, contB = 0;
    for(int i = 0; i != 8; i++){
        for(int j = 0; j != 8; j++){
            if(v[i][j] == '-'){
                continue;
            }else if(v[i][j] == 'W'){
                contW++;
            }else{
                contB++;
            }
        }
    }
    printf("Black - %2d White - %2d\n", contB, contW);
}

bool move(vector<string>& v, char p, bool prt){
    bool validate = true;
    set<string> st;

    for(int i = 0; i != 8; i++){
        for(int j = 0; j != 8; j++){
            if(v[i][j] != '-'){
                continue;
            }

            bool val = false;
            for(int k = i-1; k >= 0; k--){
                if(v[k][j] == '-'){
                    break;
                }else if(v[k][j] != p){
                    val = true;
                }else if(val){
                    string s = "(";
                    s += to_string(i+1);
                    s += ",";
                    s += to_string(j+1);
                    s += ")";

                    st.insert(s);
                    validate = false;
                    break;
                }else{
                    break;
                }
            }

            val = false;
            for(int k = i+1; k < 8; k++){
                if(v[k][j] == '-'){
                    break;
                }else if(v[k][j] != p){
                    val = true;
                }else if(val){
                    string s = "(";
                    s += to_string(i+1);
                    s += ",";
                    s += to_string(j+1);
                    s += ")";

                    st.insert(s);

                    validate = false;
                    break;
                }else{
                    break;
                }
            }

            val = false;
            for(int k = j-1; k >= 0; k--){
                if(v[i][k] == '-'){
                    break;
                }else if(v[i][k] != p){
                    val = true; 
                }else if(val){
                    string s = "(";
                    s += to_string(i+1);
                    s += ",";
                    s += to_string(j+1);
                    s += ")";

                    st.insert(s);


                    validate = false;
                    break;
                }else{
                    break;
                }
            }

            val = false;
            for(int k = j+1; k < 8; k++){
                if(v[i][k] == '-'){
                    break;
                }else if(v[i][k] != p){
                    val = true; 
                }else if(val){
                    string s = "(";
                    s += to_string(i+1);
                    s += ",";
                    s += to_string(j+1);
                    s += ")";

                    st.insert(s);

                    validate = false;
                    break;
                }else{
                    break;
                }
            }

            val = false;
            for(int k = 1; k != 8; k++){
                if(i-k < 0 || j-k < 0 || v[i-k][j-k] == '-'){
                    break;
                }if(v[i-k][j-k] != p){
                    val = true;
                }else if(val){
                    string s = "(";
                    s += to_string(i+1);
                    s += ",";
                    s += to_string(j+1);
                    s += ")";

                    st.insert(s);


                    validate = false;
                    break;
                }else{
                    break;
                }
            }

            val = false;
            for(int k = 1; k != 8; k++){
                if(i+k >= 8 || j+k >= 8 || v[i+k][j+k] == '-'){
                    break;
                }if(v[i+k][j+k] != p){
                    val = true;
                }else if(val){
                    string s = "(";
                    s += to_string(i+1);
                    s += ",";
                    s += to_string(j+1);
                    s += ")";

                    st.insert(s);


                    validate = false;
                    break;
                }else{
                    break;
                }
            }
            val = false;
            for(int k = 1; k != 8; k++){
                if(i-k < 0 || j+k >= 8 || v[i-k][j+k] == '-'){
                    break;
                }if(v[i-k][j+k] != p){
                    val = true;
                }else if(val){
                    string s = "(";
                    s += to_string(i+1);
                    s += ",";
                    s += to_string(j+1);
                    s += ")";

                    st.insert(s);


                    validate = false;
                    break;
                }else{
                    break;
                }
            }

            val = false;
            for(int k = 1; k != 8; k++){
                if(i+k >= 8 || j-k < 0 || v[i+k][j-k] == '-'){
                    break;
                }if(v[i+k][j-k] != p){
                    val = true;
                }else if(val){
                    string s = "(";
                    s += to_string(i+1);
                    s += ",";
                    s += to_string(j+1);
                    s += ")";

                    st.insert(s);


                    validate = false;
                    break;
                }else{
                    break;

                }
            }        
        }
    } 

    if(validate){
        if(prt){
            cout << "No legal move." << endl;
        }
        return false;
    }else if(prt){
        bool f = true;

        for(auto it : st){
            if(f){
                f = false;
            }else{
                cout << " ";
            }
            cout << it;
        }
        cout << endl;
    }
    return true;
}

int main(){
    int t;
    cin >> t;

    int test = 1;
    while(t--){
        if(test != 1){
            cout << endl;
        }test++;

        vector<string> v(8);
        for(int i = 0; i != 8;i++){
            cin >> v[i];
        }

        char player;
        cin >> player;

        string s;
        while(cin >> s){
            if(s == "Q"){
                break;
            }

            if(s == "L"){
                move(v, player, true);
            }else{
                if(!move(v, player, false)){
                    if(player == 'W'){
                        player = 'B';
                    }else{
                        player = 'W';
                    }
                }

                input(v, s[1]-'0', s[2]-'0', player);
                contar(v);
                if(player == 'W'){
                    player = 'B';
                }else{
                    player = 'W';
                }
            }
        }

        for(int i = 0; i != 8; i++){
            cout << v[i] << endl;
        }
    }
}
