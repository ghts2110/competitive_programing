#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main(){
    int n, m;
    while(cin >> n >> m){
        if(!n && !m){
            break;
        }

        map<int, bool> mp;
        for(int i = 0; i != n; i++){
            int num;
            cin >> num;
            mp[num] = true;
        }

        int ans = 0;
        for(int i = 0; i != m; i++){
            int num;
            cin >> num;

            if(mp[num]){
                ans++;
            }
        }

        cout << ans << endl;
    }
}