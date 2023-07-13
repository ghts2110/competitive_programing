#include <iostream>
#include <cmath>

using namespace std;

long long value, n, m, k;

int validate(long long mid){
    long long cont = 0;

    for (int i = 1; i <= n; i++) {
        cont += min(m, mid / i);
    }
 
    if(cont < k){
        return 1;
    }
    return 0;
}

long long bs(long long start, long long end){
    long long mid = (start + end)/2;

    if(start > end){
        return value;
    }
    
    if(validate(mid) == 1){
        return bs(mid + 1, end);
    }

    value = mid;
    return bs(start, mid - 1);
}

int main(){
    cin >> n >> m >> k;
    
    value = k;
    cout << bs(1, k) << endl;
}
