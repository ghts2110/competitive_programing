#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    int x, y;

    int test = 1;
    while(cin >> x >> y){
        if(x == 0){
            break;
        }

        vector<vector<char>> v(x, vector<char> (y));
        int cont = 0;
        vector<vector<int>> num(x, vector<int> (y));

        for(int i = 0; i != x; i++){
            for(int j = 0; j != y; j++){
                char c;
                cin >> c;
                v[i][j] = c;

                if(v[i][j] != '*' && (i == 0 || j == 0 || v[i-1][j] == '*' || v[i][j-1] == '*')){
                    cont++;     
                    num[i][j] = cont;
                }
            }
        }

        if(test != 1){
            cout << endl;
        }
        cout << "puzzle #"<<test<<":" << endl;
        test++;

        cout << "Across" << endl;
        string s = "";

        int n = -1;
        for(int i = 0; i != x; i++){
            for(int j = 0; j != y; j++){
                if(v[i][j] != '*'){
                    s += v[i][j];
                    if(n == -1){
                        n = num[i][j];
                    }
                }

                if((v[i][j] == '*' || j == y-1) && s.size() != 0){
                    printf("%3d.", n);
                    n = -1;
                    cout << s << endl;
                    s = "";
                }
            } 
        }

        cout << "Down" << endl;
        n = -1;
        for(int i = 0; i != x; i++){
            for(int j = 0; j != y; j++){
                if(v[i][j] != '*'){
                    if(n == -1){
                        n = num[i][j];
                    }
                    for(int k = i; k != x; k++){
                        if(v[k][j] == '*'){
                            break;
                        }

                        s += v[k][j];
                        v[k][j] = '*'; 
                    }
                    
                    printf("%3d.", n);
                    n = -1;
                    cout << s << endl;
                    s = "";
                }

            } 
        }
    }
}
