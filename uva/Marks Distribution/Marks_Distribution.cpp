#include <iostream>
#include <cstring>
using namespace std;
int n,t,p;
int mem[72][72];

int recursive(int ind,int s){
    if(s == t){
        return 1;
    }
    if(s > t){
        return 0;
    }
    if(ind >= n){
        return 0;
    }

    if(mem[ind][s] != -1){
        return mem[ind][s];
    }

    int cont = 0;
    for(int i = 0; i <= t - s; i++){
        cont += recursive(ind+1,s+i);
    }

    return mem[ind][s] = cont;
}
int main(){
    int test;
    cin >> test;

    while(test--){
        cin >> n >> t >> p;
        memset(mem,-1,sizeof(mem));
        cout << recursive(0,n*p) << endl;
    }   
}
