#include <iostream>

using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        int n, num, mx = 0, cont = 0;
        cin >> n;
        
        for(int i = 0; i != n; i++){
            cin >> num;
            
            cont += num;
            mx = max(mx, cont);
            
            if(cont < 0){
                cont = 0;
            }

        }

         
        cout << mx << endl;
    }
}
