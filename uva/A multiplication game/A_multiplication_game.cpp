#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int main(){
    long long x = 1;
    long long y = 9;
    vector<long long> v;
    for(int i = 0; i != 100; i++){
        v.push_back(x*y);
        if(x * y > 4294967295){
            break;
        }
        if(i %2 == 0){
            x*=2;
        }else{
            y*=9;
        }
    }

    int n;
    while(cin >> n){
        int ind = lower_bound(v.begin(), v.end(), n) - v.begin();     
        if(ind % 2 == 0){
            cout << "Stan wins." << endl;
        }else{
            cout << "Ollie wins." << endl;
        }
    }
}
