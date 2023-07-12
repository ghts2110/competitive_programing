#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;

    vector<vector<char> > v(n);

    for(int i = 0; i != n; i++){
        for(int j = 0; j != n; j++){
            char num;
            cin >> num;

            v[i].push_back(num);
        }
    }

    int cont = 0, value = 0;
    for(int i = 0; i != n; i++){
        if(i % 2 == 0){
            for(int j = 0; j != n; j++){
                if(v[i][j] == 'o'){
                    cont++;
                }else if(v[i][j] == 'A'){
                    value = max(value, cont);
                    cont = 0;
                }
            }
        }else{
            for(int j = n-1; j != -1; j--){
                if(v[i][j] == 'o'){
                    cont++;
                }else if(v[i][j] == 'A'){
                    value = max(value, cont);
                    cont = 0;
                }
            }
        }
    }
    value = max(value, cont);

    cout << value << endl;
}
