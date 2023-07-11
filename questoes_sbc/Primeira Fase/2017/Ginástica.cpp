#include <iostream>
#include <cstring>

using namespace std;

int m, n;

long long mem[50][100000];

long long dp(int t, int k){
    if(t == 0){
        return 1;
    }

    if(mem[t][k] != -1){
        return mem[t][k];
    }

    long long cont = 0;
    
    if(k < n){
        cont += dp(t-1, k+1);
    }

    if(k > m){
        cont += dp(t-1, k-1);
    }

    mem[t][k] = cont;
    return cont;
}

int main(){
    int t;

    cin >> t >> m >> n;
   
    n = n-m;
    m = m-m;
    t--;

    long long cont = 0;
    
    memset(mem, -1, sizeof(mem));

    for(int i = m; i != n + 1; i++){
        cont += dp(t, i) % 1000000007;
    }
 
    cout << cont % 1000000007 << endl;
    
}
