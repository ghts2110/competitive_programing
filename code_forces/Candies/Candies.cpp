#include <iostream>

using namespace std;

long long value, n, true_mid;

int validate(long long mid){
    long long newN = n, sum = 0;

    while(newN > 0 && sum < true_mid){
        sum += min(mid, newN);
        newN -= mid;
        newN -= newN/10;  

    } 

    if(sum >= true_mid){
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
        value = min(value, mid);
        return bs(start, mid-1);
    }

    return bs(mid+1, end);
}

int main(){
    cin >> n;

    true_mid = value = n/2;
    if(n%2 == 1){
        value++;
        true_mid++;
    }

    cout << bs(1, true_mid) << endl;
}
