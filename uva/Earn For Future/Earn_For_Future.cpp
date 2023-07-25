#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int t;
    cin >> t;

    int cont = 1;
    while(t--){
        cout << "Case "<<cont<<": ";
        cont++;
        
        int n;
        cin >> n;
    
        int mx = 0;
        for(int i = 0; i != n; i++){
            int num;
            cin >> num;

            mx = max(mx, num);
        }

        cout << mx << endl;
    }
}
