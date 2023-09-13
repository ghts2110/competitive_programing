#include <iostream>
#include <vector>

using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        vector<vector<char> > v(3, vector<char>(3));
        int cont = 0;
        for(int i = 0; i != 3; i++){
            for(int j = 0; j != 3; j++){
                cin >> v[i][j];
                if(v[i][j] == '1'){
                    cont++;
                }
            }
        }

        vector<vector<char> > save(3, vector<char>(3));

        int asw = -1;
        while(cont!=0){
            cont = 0;
            asw++;

            for(int i = 0; i != 3; i++){
                for(int j = 0; j != 3; j++){
                    int sum = 0;

                    if(i-1 > -1){
                        sum += v[i-1][j]-'0';
                    }if(i + 1 != 3){
                        sum += v[i+1][j]-'0';
                    }if(j-1 > -1){
                        sum += v[i][j-1]-'0';
                    }if(j + 1 != 3){
                        sum += v[i][j+1]-'0';
                    }

                    sum %= 2;
                    if(sum == 1){
                        cont++;
                    }

                    save[i][j] = char('0'+sum);
                }
            }
            v = save;
        }
        cout << asw << endl;
    }
}