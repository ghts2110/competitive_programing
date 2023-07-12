#include <iostream>
#include <vector>

using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        int n, u;
        cin >> n >> u;
        
        vector<long long> v1(n+1), v2(n+1);
        
        for(int i = 0; i != u; i++){
            int l, r, val;
            cin >> l >> r >> val;

            v1[l] += val;
            v1[r+1] -= val;
        }

        int cont = 0;
        for(int i = 0; i != n; i++){
            cont += v1[i];
            v2[i] = cont;
        }

        int q;
        cin >> q;

        for(int i = 0; i != q; i++){
            int index;
            cin >> index;

            cout << v2[index] << endl;
        }
    }
}
