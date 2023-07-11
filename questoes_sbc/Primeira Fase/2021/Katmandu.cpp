#include <iostream>

using namespace std;

int main(){
    int t, d, m, y;
    cin >> t >> d >> m;
    
    int i = 0;
    char c = 'N';

    while(m--){
        cin >> y;
        if(y - i >= t){
            c = 'Y';
        }

        i = y;
    }

    if(d - i >= t){
        c = 'Y';
    }

    cout << c << endl;
}
