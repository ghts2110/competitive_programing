#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int l, d, h, v;
    int t;
    cin >> t;
    while(t--){
        cin >> l >> d >> h >> v;
        double t =sqrt((2*h)/9810.0);
        double dist = t*v;

        if((dist >= d-500 && dist <= d+500) || (dist >= d+l-500 && dist <= d+l+500)){
            cout << "EDGE" << endl;
        }else if(dist <= d || dist > d+l){
            cout << "FLOOR" << endl;
        }else{
            cout << "POOL" << endl;
        }
    }
}
