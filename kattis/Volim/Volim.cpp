#include <iostream>

using namespace std;

int main(){
    int k;
    cin >> k;
    int n, time = 210;
    cin >> n;

    int t;
    char c;
    for(int i = 0; i != n; i++){
        cin >> t >> c;
        time -= t;
        if(time < 0){
            cout << k << endl;
            break;
        }

        if(c == 'T'){
            k++;
            if(k == 9){
                k = 1;
            }
        }
    }

}
