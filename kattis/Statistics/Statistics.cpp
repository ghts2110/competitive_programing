#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int t, cont = 1;
    while(cin >> t){
        cout << "Case "<<cont<<": ";
        cont++;

        int mx = -1e9, mn = 1e9;
        for(int i = 0; i != t; i++){
            int num;
            cin >> num;

            mx = max(mx, num);
            mn = min(mn, num);
        }
        
        cout << mn << " " << mx << " " << mx-mn << endl;
    }

}
