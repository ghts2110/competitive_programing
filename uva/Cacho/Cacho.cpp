#include <iostream>

using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        int l, r;
        bool v = true;

        cin >> l;
        for(int i = 0; i != 4; i++){
            cin >> r;
            if(r - 1 != l){
                v = false;
            }
            
            l = r;
        }

        if(v){
            cout << "Y" << endl;
        }else{
            cout << "N" << endl;
        }
    }
}
