#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    while(cin >> n){
        vector<int> v(n);

        for(int i = 0; i != n; i++){
            cin >> v[i];
        }

        vector<bool> val(n, true);
        int mx = -1e9, index = 0;
        for(int i : v){
            if(mx > i){
                val[index] = false;
            }else{
                mx = i;
            }
            index++;
        }

        int mn = 1e9;

        for(int i = v.size()-1; i != -1; i--){
            if(mn < v[i]){
                val[i] = false;
            }else{
                mn = v[i];
            }
        }

        int cont = 0;
        for(bool b : val){
            if(b){
                cont++;
            }
        }

        cout << cont << endl;
    }
}