#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;

long long bs(long long start, long long end, long long key){
    if(start > end){
        return -1;
    }

    long long mid = (start+end)/2;

    if(v[mid] == key){
        return mid;
    }

    if(v[mid] > key){
        return bs(start, mid-1, key);
    }

    return bs(mid+1, end, key);
}

int main(){
    long long n, k;

    cin >> n >> k;

    for(int i = 0; i != n; i++){
        long long num; 
        cin >> num;
        v.push_back(num);
    }

    sort(v.begin(), v.end());

    long long cont = n, vl1, vl2;
    for(int i = 0; i < n; i++){
        vl1 = bs(-1, n, v[i]*k);
        vl2 = bs(-1, n, v[vl1]*k);

        if(v[i] == -1 || (vl1 != -1 && vl2 == -1)){
            cont--;
        }else if(vl1 != -1 && vl2 != -1){
            v[vl1] = -1;
        }
    }    

    cout << cont << endl;
}


