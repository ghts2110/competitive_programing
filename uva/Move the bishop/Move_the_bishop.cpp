#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        int n, k;
        cin >> k >>n;
        
        for(int i = 0; i != k; i++){
            int x, y, a, b;
            cin >> x >> y >> a >> b;
            if((x+y)%2==(a+b)%2){
                if(x == a && y == b){
                    cout << 0 << endl;
                }else if(x-y == a-b || abs(x-a) == abs(y-b)){
                    cout << 1 << endl;
                }else{
                    cout << 2 << endl;
                }
            }else{
                cout << "no move" << endl;
            }
        }
    }
}
