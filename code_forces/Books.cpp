#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, t;

int main(){
    cin >> n >> t;
    vector<int> v;

    for(int i = 0; i != n; i++){
        int a;
        cin >> a;
        v.push_back(a);
    }
    
    int cont = 0, sum = 0, index = 0, mx = 0;
    for(int i = 0; i != n; i++){
        sum += v[i];
        cont++; 
        if(sum <= t){
            mx = max(cont, mx);
        }else{
            sum -= v[index];
            index++;
            cont--;
        }
    }

    cout << mx << endl;
}
