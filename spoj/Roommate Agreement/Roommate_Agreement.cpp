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

        vector<int> v(n+1, 0);

        for(int i = 0; i != n; i++){
            int num;
            cin >> num;

            v[i+1] = v[i] + num;     
        }

        sort(v.begin(), v.end());

        long long cont = 1, asw = 0;
        for(int i = 1; i <= n; i++){
            if(v[i] == v[i-1]){
                cont++;
            }
            if(v[i] != v[i-1] || i == n){
                asw += (cont*(cont-1))/2;
                cont = 1;
            }
        }


        cout << asw << endl;
    }
}
