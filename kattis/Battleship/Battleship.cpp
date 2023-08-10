#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        int a, b, c;
        cin >> a >> b >> c;

        vector<vector<char>> v1(b, vector<char> (a)), v2(b, vector<char> (a));
        int b1 = 0, b2 = 0;
        for(int i = b-1; i != -1; i--){
            for(int j = 0; j != a; j++){
                cin >> v1[i][j];
                if(v1[i][j] == '#'){
                    b1++;
                }
            }
        }

        for(int i = b-1; i != -1; i--){
            for(int j = 0; j != a; j++){
                cin >> v2[i][j]; 
                if(v2[i][j] == '#'){
                    b2++;
                }
            }
        }

        vector<pair<int, int>> p1(c);
        int j = 0;
        for(int i = 0; i != c; i++){
            int x, y;
            cin >> x >> y;

            if(j == 1){
                if(v1[y][x] == '#'){
                    v1[y][x] = '_';
                    b1--;
                    if(b1 == 0){
                        j = 0;
                    }
                }else{
                    j = 0;
                }
            }else{
                if(v2[y][x] == '#'){
                    v2[y][x] = '_';
                    b2--;
                    if(b2 == 0){
                        j = 1;
                    }
                }else{
                    j = 1;
                }
            }
        }

        if((b1 == 0 && b2 == 0) || (b1 != 0 && b2 != 0)){
            cout << "draw" << endl;
        }else if(b1 > 0){
            cout << "player one wins" << endl;
        }else{
            cout << "player two wins" << endl;
        }
        
    }
}
