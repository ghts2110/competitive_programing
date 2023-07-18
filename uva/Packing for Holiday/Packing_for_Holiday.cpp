#include <iostream>

using namespace std;

int main(){
    int t;
    cin >> t;

    int cont = 1;
    while(t--){
        int l, w, h;
        cin >> l >> w >> h;

        if(l > 20 || w > 20 || h > 20){
            printf("Case %d: bad\n", cont); 
        }else{
            printf("Case %d: good\n", cont);
        }
        cont++;

    }
}
