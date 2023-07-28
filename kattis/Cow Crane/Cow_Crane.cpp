#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int n, m;
    while(cin >> n >> m){
        int p1, p2;
        cin >> p1 >> p2;
        int t1, t2;
        cin >> t1 >> t2;

        int cont = abs(0 - n) + abs(n - m) + abs(m - p2);
        if(cont <= t2 && cont + abs(p2 - m) + abs(m - p1) <= t1){
            cout << "possible" << endl;
            continue;
        }
        cont = abs(0 - n) + abs(n - p1);
        if(cont <= t1 && cont + abs(p1 - m) + abs(m - p2) <= t2){
            cout << "possible" << endl;
            continue;
        }
        cont = abs(0 - m) + abs(m - n) + abs(n - p1);
        if(cont <= t1 && cont + abs(p1 - n) + abs(n - p2) <= t2){
            cout << "possible" << endl;
            continue;
        }
        cont = abs(0 - m) + abs(m - p2);
        if(cont <= t2 && cont + abs(p2 - n) + abs(n - p1) <= t1){
            cout << "possible" << endl;
            continue;
        }
       
        cout << "impossible" << endl;
    }
}
