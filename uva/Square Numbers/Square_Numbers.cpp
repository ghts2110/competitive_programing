#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int n, m;
    while(cin >> n >> m){
        if(n == 0){
            break;
        }
        
        int asw = 0;
        for(int i = n; i <= m; i++){
            double d = sqrt(i);
            if(d == int(d)){
                asw++;
            }
        }

        cout << asw << endl;
    }
}
