#include <iostream>

using namespace std;

int main(){
    int t, l, r;
    cin >> t;
        
    cout << "Lumberjacks:" << endl;
    while(t--){
        cin >> l >> r;


        int o;
        if(l > r){
            o = 1;
        }else{
            o = 0;
        }

        l = r;
        bool validate = true;
        for(int i = 0; i != 8; i++){
            cin >> r;
            if((o == 1 && l < r) || (o == 0 && l > r)){
                validate = false;
            }

            l = r;
        }

        if(validate){
            cout << "Ordered" << endl;
        }else{
            cout << "Unordered" << endl;
        }

    }
}
