#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int a, b, c;
    while(cin >> a >> b >> c){
        vector<int> v(105);
        for(int i = 0; i != 3; i++){
            int x, y;
            cin >> x >> y;
            v[x] += 1;
            v[y] -= 1;
        }

        int cont = 0; 
        for(int i = 1; i <= 100; i++){
            v[i] += v[i-1];
            if(v[i] == 0){
                continue;
            }else if(v[i] == 1){
                cont += a;
            }else if(v[i] == 2){
                cont += 2*b;
            }else{
                cont += 3*c;
            }
        }

        cout << cont << endl;
    }
}
