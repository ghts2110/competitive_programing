#include <iostream>
#include <vector>
#include <bitset>
#include <cmath>

#define pb push_back

using namespace std;

int main(){
    int n, m, c;

    int t =  1;
    while(cin >> n >> m >> c){
        if(n == 0){
            break;
        }

        cout << "Sequence " << t << endl;
        t++;

        vector<int> v;
        for(int i = 0;i != n; i++){
            int num;
            cin >> num;

            v.pb(num);
        }
            
        bitset<21> bt(0);
        int cont = 0, mx = 0;
        bool validate = true;
        for(int i = 0; i != m; i++){
            int num;
            cin >> num;

            if(bt[num] == 0){
                cont += v[num-1];
                bt[num] = 1;
            }else{
                bt[num] = 0;
                cont -= v[num-1];
            }   
            
            if(cont > c){
                validate = false;
            }else{
                mx = max(mx, cont);
            }
        }
    
        if(validate){
            cout << "Fuse was not blown." << endl;
            cout << "Maximal power consumption was "<<mx<<" amperes."<<endl;
        }else{
            cout << "Fuse was blown." << endl;
        }
        cout << endl;
    }
}
