#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    while(1){
        cin >> n;

        if(n == 0){
            break;
        }

        vector<long long> v;
        for(int i = 0; i != n; i++){
            long long n;
            cin >> n;

            v.push_back(n);
        }
        
        long long cont = 0;
        v.push_back(0);
        for(int i = 0; i != n; i++){
            if(v[i] >= 0){
                cont += v[i];
            }else{
                cont -= v[i];
            }
            v[i+1] += v[i];
        }

        cout << cont << endl;
    }
}
