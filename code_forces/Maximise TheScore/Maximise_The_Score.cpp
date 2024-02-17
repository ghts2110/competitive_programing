#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        vector<int> v(n*2);
        for(int i = 0; i != 2*n; i++){
            cin >> v[i];
        }

        sort(v.begin(), v.end());

        int sum = 0; 
        for(int i = 0; i != 2*n; i+=2){
            sum += v[i];
        }

        cout << sum << endl;
    }
}
