#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

vector<int> weight, value; 
int n, mem[2010][2010];

int dp(int i, int w){
    if(i == n || w < 0){
        return 0;
    }
    if(mem[i][w] != -1){
        return mem[i][w];
    }
     
    int np = 0, p = 0;
    np += dp(i+1, w);
    p += dp(i+1, w-weight[i]);
    
    if(w - weight[i] >= 0){
        p += value[i];
    }
    
    if(p > np){
        mem[i][w] = p;
        return p;
    }else{
        mem[i][w] = np;
        return np;
    }
}

int main(){
    int s, max;

    memset(mem, -1, sizeof(mem));

    cin >> s >> n;
    for(int i = 0; i != n; i++){
        int w, v;
        cin >> w >> v;

        weight.push_back(w);
        value.push_back(v);
    }

    max = dp(0, s);
    cout << max << endl;
}
