#include <iostream>
#include <map>
#include <string>

using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        long long n, k;
        cin >> n >> k;
        map<long long, bool> mp;

        while(!mp[k]){
            mp[k] = true;
            k = k * k;

            string s = to_string(k);
            while(s.size() > n){
                s.erase(s.end()-1);
            }

            k = stoi(s);
        }

        long long mx = 0;
        for(auto it : mp){
            mx = max(mx, it.first);
        }

        cout << mx << endl;
    }
}
g