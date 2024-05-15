#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    long long n;
    vector<int> v;
    while(cin >> n){
        v.push_back(n);
        sort(v.begin(), v.end());
        int sz = v.size();
        
        if(sz % 2 == 1){
            cout << v[sz/2] << endl;
        }else{
            int cont = v[sz/2];
            cont += v[sz/2 -1];
            cont /= 2;
                
            cout << cont << endl;
        }
    }
}
