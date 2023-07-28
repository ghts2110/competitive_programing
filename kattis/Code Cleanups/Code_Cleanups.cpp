#include <iostream>
#include <vector>

#define pb push_back

using namespace std;

int main(){
    int n;
    while(cin >> n){
        vector<int> v;
        for(int i = 0; i != n; i++){
            int num;
            cin >> num;
            
            v.pb(num);
        }
        v.pb(1e9);

        int cont = 1, sum = 0, asw = 0;
        for(int i = 1; i <= n; i++){
            if((v[i] - v[i-1]) * cont + sum > 19){
                cont = 1;
                asw++;
                sum = 0;
            }else{
                sum += (v[i] - v[i-1]) * cont;
                cont++;
            }
        }
         
        if(sum != 0){
            asw++;
        }
        cout << asw << endl;
    }
}
