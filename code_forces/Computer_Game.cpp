#include <iostream>

using namespace std;

int value;
int k, n, a, b, mx;

int validate(int mid){
    int newK = k - (mid*a);   

    if(newK > b){
        if(newK % b == 0){
            mid += (newK/b)-1;
        }else{
            mid += newK/b;
        }
    }

    if(mid >= n){
        return 1;
    }
    return 0;
}

int bs(int start, int end){
    int mid = (start + end)/2;

    if(start > end){
        return value;
    }

    if(validate(mid) == 1){
        value = max(value, mid);
        return bs(mid+1, end);
    }

    return bs(start, mid-1);
}

int main(){
    int t;
    cin >> t;

    while(t--){
        value = -1;
        cin >> k >> n >> a >> b;

        if(k%a == 0){
            mx = k/a;
            mx--;
        }else{
            mx = k/a;
        }

        cout << bs(0, min(mx,n))<< endl;
    }
}
