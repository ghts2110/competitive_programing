#include <iostream>

using namespace std;

int main(){
    int t;
    cin >> t;

    int cont = 1;
    while(t--){
        bool v = true;
        for(int i = 0; i != 13; i++){
            int num;
            cin >> num;

            if(num == 0){
                v = false;
            }
        }
        
        cout << "Set #"<<cont<<": ";
        cont++;
        if(v){
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }
    }

}
