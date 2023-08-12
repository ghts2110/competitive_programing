#include <iostream>
#include <vector>

#define pb push_back

using namespace std;

int main(){
    long long n;
    while(cin >> n){
        if(n < 0){
            break;
        }else if(n == 0){
            cout << 0 << endl;
            continue;
        }
        
        vector<int> v;
        while(n != 0){
            v.pb(n%3);
            n /= 3;
        }

        for(int i = 0; i != v.size(); i++){
            cout << v[v.size()-1-i];
        }
        cout << endl;
    }
}
