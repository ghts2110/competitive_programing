#include <iostream>
#include <vector>

#define pb push_back

using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        
        vector<int> v;
        for(int i = 0; i != n; i++){
            int num;
            cin >> num;

            v.pb(num);
        }

        int mx = 0, l = 0;
        for(int i = 1; i != n; i++){
            if(v[l] > v[i]){
                mx = max(mx, v[l]-v[i]);
            }else{
                l = i;
            }
        }

        if(mx == 0){
            int mn = 1e9;
            for(int i = 1; i != n; i++){
                mn = min(mn, v[i]-v[i-1]);
            }
            mx = -mn;
        }

        cout << mx << endl;
    }
}
