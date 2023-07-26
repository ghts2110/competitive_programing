#include <iostream>

using namespace std;

int main(){
    double c, x, m;
    while(cin >> c >> x >> m){
        int value = 0;
        for(int i = 0; i != 6; i++){
            double v, l;
            cin >> v >> l;

            if(c/2 >= (m/l) + (x * (m/v))){
                value = v;
            }
        }

        if(value == 0){
            cout << "NO" << endl;
        }else{
            cout << "YES " << value << endl;
        }
    }
}
