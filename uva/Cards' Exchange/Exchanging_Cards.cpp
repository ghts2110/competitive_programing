#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

int main(){
    int a, b;
    while(cin >> a >> b){
        if(a == 0){
            break;
        }

        vector<int> ca(a), cb(b);
        bitset<100001> bt1(0), bt2(0); 
        for(int i = 0; i != a; i++){
            cin >> ca[i];
            bt1[ca[i]] = 1;
        }

        for(int i = 0; i != b; i++){
            cin >> cb[i];
            bt2[cb[i]] = 1;
        }

        int mn = 1e9, cont = 0;
    
        for(int i = 0; i != a; i++){
            if(bt2[ca[i]] == 0){
                bt2[ca[i]] = 1;
                cont++;
            }
        }

        mn = cont;
        cont = 0;

        for(int i = 0; i != b; i++){
            if(bt1[cb[i]] == 0){
                cont++;
                bt1[cb[i]] = 1;
            }
        }

        if(mn > cont){
            mn = cont;
        }

        cout << mn << endl;
    }
}
