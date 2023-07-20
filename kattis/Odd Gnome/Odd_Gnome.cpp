#include <iostream>

using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        int l, r;
        cin >> l;

        int v = 1;
        for(int i = 2; i <= n; i++){
            cin >> r;
            if(r - 1 != l && v == 1){
                cout << i << endl;
                v = 0;
            }
            
            l=r;
        }
    }
}
