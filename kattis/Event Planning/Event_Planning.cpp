#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int n, b, h, w;
    while(cin >> n >> b >> h >> w){
        int p;
        
        int home = true;
        int mn = 1e9;
        for(int i = 0; i != h; i++){
            cin >> p;

            int cont = 0;
            for(int i = 0; i != w; i++){
                int num; 
                cin >> num;

                if(num >= n){
                    cont++;
                }
            }
           
            if(p * n <= b && cont != 0){
                home = false;
                mn = min(p * n, mn);
            }
        }

        if(home){
            cout << "stay home" << endl;
        }else{
            cout << mn << endl;
        }

    }
}
