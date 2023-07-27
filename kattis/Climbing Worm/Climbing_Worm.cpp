#include <iostream>

using namespace std;

int main(){
    int a, b, h;
    while(cin >> a >> b >> h){
        int cont = 0, sum = 0;
        while(sum < h){
            cont++;
            sum+=a;
            if(sum >= h){
                break;
            }
            sum-=b;
        }
        
        cout << cont << endl;
    }
}
