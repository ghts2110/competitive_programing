#include <iostream>
#include <vector>
#include <string.h>

using namespace std;
const int mx = 100010;

vector<long long> value(mx, 0);
vector<long long> query(mx, 0);
vector<long long> store(mx, 0);
vector<vector<long long> > operations(mx);

int main(){
    long long n, m, k, cont;
    cin >> n >> m >> k;

    for(int i = 0; i != n; i++){
        cin >> value[i];
    }  

    for(int i = 0; i != m; i++){
        long long num;
        cin >> num;
        operations[i].push_back(num-1);
        
        cin >> num;
        operations[i].push_back(num);
        
        cin >> num;
        operations[i].push_back(num);
    }

    for(int i = 0; i != k; i++){
        long long x, y;
        cin >> x >> y;

        query[x-1]++;
        query[y]--;
    }

    cont = 0;
    for(int i = 0; i != m; i++){
        cont += query[i];
        store[operations[i][0]] += cont * operations[i][2];
        store[operations[i][1]] -= cont * operations[i][2];
    } 
    
    cont = 0;
    for(int i = 0; i != n; i++){
        cont += store[i];
        cout << cont + value[i] << " ";
    }
    cout << endl;
}

