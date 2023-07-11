#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;
long long n, m;

long long sum(long long h){
    long long s = 0;
    for(int i = n-1; i != -1; i--){
        if(v[i] - h <= 0){
            break;
        }
        s += v[i] - h;
    }
    
    return s;
}

int bs(int start, int end, int key){
    int mid = (start + end)/2;
    long long s = sum(mid);

    if(start > end){
        return end;
    }

    if(s == key){
        return mid;
    }

    if(s < key){
        return bs(start, mid-1, key);
    }

    return bs(mid+1, end, key);
}

int main(){
    cin >> n >> m;
    
    for(int i = 0; i != n; i++){
        int num;
        cin >> num;
        v.push_back(num);
    }

    sort(v.begin(), v.end());

    cout << bs(0, v[n-1], m) << endl;
}
