#include <iostream>
#include <vector>

using namespace std;

int main(){
    int t;

    int test = 1;
    while(cin >> t){
        if(t == 0){
            break;
        }
        
        vector<int> asw(t), v(t);
        for(int i = 0; i != t; i++){
            cin >> asw[i];
        }

        cout << "Game "<<test<<":" << endl;
        test++;
        
        while(1){
            int cont = 0;
            for(int i = 0; i != t; i++){
                cin >> v[i];
                cont += v[i];
            }

            if(cont == 0){
                break;
            }

            vector<int> save = asw;
            int x = 0, y = 0;
            for(int i = 0; i != t; i++){
                if(save[i] == v[i]){
                    x++;
                    save[i] = v[i] = 0; 
                }
            }
            for(int i = 0; i != t; i++){
                if(save[i] != 0){
                    for(int j = 0; j != t; j++){
                        if(save[i] == v[j]){
                            y++;
                            save[i] = v[j] = 0;
                            break;
                        }
                    }
                }
            }

            cout << "    ("<<x<<","<<y<<")"<<endl;
        }
    }
}
