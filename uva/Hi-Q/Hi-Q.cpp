#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> v(7, vector<int> (7));
vector<vector<char>> t(7, vector<char> (7, 'O'));

pair<int, pair<int, int>> move(){
    pair<int, pair<int, int>> p;

    for(int i = 0; i != 7; i++){
        for(int j = 0; j != 7; j++){
            if(t[i][j] == ' '){
                continue;
            }

            if(t[i][j] == 'X'){
                int pino1 = 0, pino2 = 0, mx = 0;
                if(i-1 >= 0 && t[i-1][j] == 'X' && i-2 >= 0 && t[i-2][j] == 'O'){
                    pino1 = v[i][j];
                    pino2 = v[i-1][j];
                    mx = v[i-2][j]; 

                    if(p.first < mx){
                        p.first = mx;
                        p.second.first = pino1;
                        p.second.second = pino2;
                    }else if(p.first == mx && p.second.first < pino1){
                        p.first = mx;
                        p.second.first = pino1;
                        p.second.second = pino2;
                    }
                }
                if(i+1 < 7 && t[i+1][j] == 'X' && i+2 <7 && t[i+2][j] == 'O'){
                    pino1 = v[i][j];
                    pino2 = v[i+1][j];
                    mx = v[i+2][j]; 

                    if(p.first < mx){
                        p.first = mx;
                        p.second.first = pino1;
                        p.second.second = pino2;
                    }else if(p.first == mx && p.second.first < pino1){
                        p.first = mx;
                        p.second.first = pino1;
                        p.second.second = pino2;
                    }
                }
                if(j-1 >= 0 && t[i][j-1] == 'X' && j-2 >= 0 && t[i][j-2] == 'O'){
                    pino1 = v[i][j];
                    pino2 = v[i][j-1];
                    mx = v[i][j-2]; 

                    if(p.first < mx){
                        p.first = mx;
                        p.second.first = pino1;
                        p.second.second = pino2;
                    }else if(p.first == mx && p.second.first < pino1){
                        p.first = mx;
                        p.second.first = pino1;
                        p.second.second = pino2;
                    }
                }
                if(j+1 < 7 && t[i][j+1] == 'X' && j+2 <7 && t[i][j+2] == 'O'){
                    pino1 = v[i][j];
                    pino2 = v[i][j+1];
                    mx = v[i][j+2]; 

                    if(p.first < mx){
                        p.first = mx;
                        p.second.first = pino1;
                        p.second.second = pino2;
                    }else if(p.first == mx && p.second.first < pino1){
                        p.first = mx;
                        p.second.first = pino1;
                        p.second.second = pino2;
                    }
                } 
            }
        }
    }

    return p;
}

int main(){
    int test;
    cin >> test;

    for(int i= 0; i != 2; i++){
        for(int j = 0; j != 2; j++){
            v[i][j] = -1;
            t[i][j] = ' ';
        }
        for(int j = 5; j != 7; j++){
            v[i][j] = -1;
            t[i][j] = ' ';
        }
    }
    for(int i = 5; i != 7; i++){
        for(int j = 0; j != 2; j++){
            v[i][j] = -1;
            t[i][j] = ' ';
        }
        for(int j = 5; j != 7; j++){
            v[i][j] = -1;
            t[i][j] = ' ';
        }
    }
    int cont = 1;
    for(int i = 0; i != 7; i ++){
        for(int j = 0; j != 7; j++){
            if(v[i][j] != -1){
                v[i][j] = cont;
                cont++;
            }
        }
    }

    cout << "HI Q OUTPUT" << endl;
    while(test--){
        int n;
 
        for(int i = 0; i != 7; i ++){
            for(int j = 0; j != 7; j++){
                if(v[i][j] != -1){
                    t[i][j] = 'O';
                }
            }
        }

        while(cin >> n){
            if(n == 0){
                break;
            }
            int cont = 0;
            for(int i = 0; i != 7; i ++){
                for(int j = 0; j != 7; j++){
                    if(v[i][j] != -1){
                        cont++;
                    }
                    if(cont == n){
                        t[i][j] = 'X';
                        break;
                    }
                }
                if(cont == n){
                    break;
                }
            }
        }

        while(1){
            pair<int, pair<int, int>> p = move();
            if(p.first == 0){
                break;
            }
            for(int i = 0; i != 7; i++){
                for(int j = 0; j != 7; j++){
                    if(p.first == v[i][j]){
                        t[i][j] = 'X';
                    }else if(p.second.first == v[i][j] || p.second.second == v[i][j]){
                        t[i][j] = 'O';
                    }
                }
            }
        }

        int sum =0;
        for(int i = 0; i != 7; i++){
            for(int j=  0; j != 7; j++){
                if(t[i][j] == 'X'){
                    sum += v[i][j];
                }
            }
        }

        cout << sum << endl;

    }
    cout << "END OF OUTPUT" << endl;
}
