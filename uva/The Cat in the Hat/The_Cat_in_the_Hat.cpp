#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int h, mx;
    while(cin >> h >> mx){
        if(h == 0 && mx == 0){
            break;
        }

        for(int n = 1; ; n++){
            long long cont = 1, num = 1, height = 0;
            int save = h;
    
            while(save != 0 && save != 1){
                height += save*num;
                num *= n;
                cont += num;
                save /= 1+n;
            }
            cont -= num;
            height += num;

            if(num == mx && save != 0){
                cout << cont << " " << height << endl;
                break;
            }
        }
    }
}
