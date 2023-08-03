#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int x, y, a, b;
    while(cin >> x >> y >> a >> b){
        if(x == 0){
            break;
        }

        if(x==a&&y==b){
            cout << 0 << endl;
        }else if(x == a || y == b || x-y==a-b || abs(x-a)==abs(y-b)){
            cout << 1 << endl;
        }else{
            cout << 2 << endl;
        }
    }
}
