#include <iostream>
#include <cmath>
#include <bitset>
#include <vector>

using namespace std;

int main(){
    int n, b;
    while(cin >> n >> b){
        if(n == 0 && b == 0){
            break;
        }
        bitset<91> bt(0);

        vector<int> v(n+1);
        for(int i = 0; i != b; i++){
            cin >> v[i];
        }

        for(int i = 0; i != b; i++){
            for(int j = 0; j != b; j++){
                bt[abs(v[i]-v[j])] = 1;
            }
        }

        int validate = true;
        for(int i = 0; i <= n; i++){
            if(bt[i] == 0){
                validate = false;
            }
        }

        if(validate){
            cout << "Y" << endl;
        }else{
            cout << "N" << endl;
        }
    }
}
