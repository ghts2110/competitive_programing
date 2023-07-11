#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int value, n, c;

int validate(int mid, vector<int> v){
    int cont = 1, index = v[1] - v[0];

    for(int i = 0; i != n-1 && cont < c; i++){
        if(index >= mid){
            cont++;
            index = v[i+2] - v[i+1]; 
        }else{
            index += v[i+2] - v[i+1];
        }
    }

    if(cont == c){
        return 1;
    }

    return 0;
}

int bs(int start, int end, vector<int> v){
    int mid = (start+end)/2;

    if(start > end){
        return value;
    }

    if(validate(mid, v) == 1){
        value = max(value, mid);
        return bs(mid+1, end, v);
    }

    return bs(start, mid-1, v);
}

int main(){
    int t;
    cin >> t;

    while(t--){
        vector<int> v;

        cin >> n >> c;

        for(int i = 0; i != n; i++){
            int num;
            cin >> num;

            v.push_back(num);
        }

        int mn = 1e9, mx = 0;
        sort(v.begin(), v.end());

        for(int i = 0; i != n - 1; i++){
            mn = min(mn, v[i+1]-v[i]);
        }

        mx = v[n-1] - v[0];
        value = mn;    

        cout << bs(mn, mx, v) << endl;
    }
}
