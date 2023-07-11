#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

int main(){
    int n, l, r, x;
    cin >> n >> l >> r >> x;

    vector<int> v(n);
    for(int i = 0; i != n; i++){
        cin >> v[i];
    }

    int value = 0;
    for(int i = 3; i <= (1<<n); i++){
        bitset<15> bt(i);
        int mn = 1e9, mx = -1, cont = 0;

        for(int j = 0; j != n; j++){
            if(bt[j] == 1){
                cont += v[j];
                mn = min(mn, v[j]);
                mx = max(mx, v[j]);
            }
        }
    
        if(cont >= l && cont <= r && mx-mn >= x){
            value++;
        }
    }

    cout << value << endl;
}
