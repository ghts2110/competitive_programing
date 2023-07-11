#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int t;
    cin >> t;

    vector<int> v;
    for(int i = 0; i != t; i++){
        int num;
        cin >> num;
               
        v.push_back(num);
    }

    sort(v.begin(), v.end());
    int cont = 1, mx = 1, value = v[0];
    for(int i = 1; i != t; i++){
        if(v[i] == v[i-1]){
            cont++;
        }else{
            if(mx < cont){
                value = v[i-1];
                mx = cont;
            }
            cont = 1;
        }
    }

    if(mx < cont){
        value = v[t-1];
    }

    cout << value << endl;
}
