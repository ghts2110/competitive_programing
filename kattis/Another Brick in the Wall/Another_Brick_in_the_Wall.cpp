#include <iostream>

using namespace std;

int main(){
    int h, w, n;
    while(cin >> h >> w >> n){
        int cont = 0;
        for(int i = 0; i != n; i++){
            int num;
            cin >> num;

            cont+= num;
            if(cont == w){
                h--;
                cont = 0;
                if(h == 0){
                    for(int j = i + 1; j != n; j++){
                        cin >> num;
                    }
                    break;
                }
            }

            if(cont > w){
                for(int j = i+1; j != n; j++){
                    cin >> num;
                }
                break;
            }
        }

        if(h == 0){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
}
