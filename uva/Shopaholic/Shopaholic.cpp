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

        vector<int> v(n);
        for(int i = 0; i != n; i++){
            cin >> v[i];
        }

        sort(v.begin(), v.end());
        int cont = 0;
        for(int i = v.size()-3; i > -1; i -= 3){
            cont += v[i];
        }

        cout << cont << endl;
    }
}
