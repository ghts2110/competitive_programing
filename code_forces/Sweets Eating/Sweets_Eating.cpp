#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n, m;
    while(cin >> n >> m){
        vector<long long> v(n);
        for (int i = 0; i < n; ++i) {
            cin >> v[i];
        }

        sort(v.begin(), v.end());

        vector<long long> asw = v;

        vector<long long> sum(m);
        sum[0] = asw[0];

        int ind = 1;
        for(int i = 1; i < n; i++){
            if(ind == m){
                ind = 0;
            }

            asw[i] = asw[i-1] + v[i] + sum[ind];
            sum[ind] += v[i];
            ind++;
        }


        for(auto it : asw){
            cout << it << " ";
        }
        cout << endl;
    }
}