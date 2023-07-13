#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>

using namespace std;

int day, w, d, f;
vector<long long> v;

int search(long long mid){
    vector<long long> test;
    int index_sub[100010];
    memset(index_sub, 0, sizeof(index_sub));

    for(int i = 0; i != f; i++){
        test.push_back(v[i]);
    }

    int sum = 0;
    for(int i = 0; i != f; i++){
        sum -= index_sub[i];
        test[i] += sum;

        if(test[i] < mid){
            long long t = mid - test[i];
            sum += t;
            index_sub[min(i+w, f)] = t;

            day -= t;
            
            if(day < 0){
                return 0;
            }
        }
    }

    return 1;
}

int main(){
    cin >> f >> d >> w;

    long long mn = 1e10, mx = 0, value;

    for(int i = 0; i != f; i++){
        long long num; 
        cin >> num;
        v.push_back(num);
        mn = min(mn, num);
        mx = max(mx, num);
    }

    mx = mn + d;
    
    value = mn;  

    while(mx >= mn){
        long long mid = (mx + mn)/2;
        day = d;

        if(search(mid) == 1){
            value = max(value, mid);
            mn = mid + 1;
        }else{
            mx = mid - 1;
        }
    }


    cout << value << endl;
}

