#include <iostream>

using namespace std;

int main(){
    double x, y;
    cin >> x >> y;

    if(x == 0 && y == 1){
        cout << "ALL GOOD" << endl;
        return 0;
    }

    if(y == 1){
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    printf("%.9f\n", x/(1-y));
}
