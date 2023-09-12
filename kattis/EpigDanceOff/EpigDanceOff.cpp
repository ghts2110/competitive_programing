#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    int x, y;
    cin >> x >> y;

    vector<string> v(x);
    for(int i = 0; i != x; i++){
        cin >> v[i];
    }

    int cont = 1;
    for(int i = 0; i != y; i++){
        for(int j = 0; j != x; j++){
            if(v[j][i] == '$'){
                break;
            }else if(j == x-1){
                cont++;
            }
        }
    }


    cout << cont << endl;
}
