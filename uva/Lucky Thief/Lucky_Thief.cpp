#include <iostream>
using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        int c,p;
        cin >> c >>p;
        int ans = ( p  - c)* c ;
        for(int i = 0; i < c; i++){
            ans += i;
        }
        cout << ans << endl;
    }
}
