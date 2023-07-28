#include <iostream>

using namespace std;

int main(){
    int w;
    while(cin >> w){
        int n;
        cin >> n;

        int cont = 0;
        while(n--){
            int x, y;
            cin >> x >> y;
            cont += x * y;
        }

        cout << cont / w << endl;
    }
}
