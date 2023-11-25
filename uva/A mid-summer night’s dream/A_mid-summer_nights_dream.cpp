#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n;
    while(cin >> n){
        vector<int> v(n);

        int equal = 0;
        int mn = 1e9, mx = -1;
        for(int i = 0; i != n; i++){
            cin >> v[i];
            mn = min(mn, v[i]);
            mx = max(mx, v[i]);

            if(mn == v[i]){
                equal++;
            }
        }

        sort(v.begin(), v.end());

        vector<int> asw;
        asw.push_back(mn);
        mn++;

        while(mn <= mx){
            int ind = lower_bound(v.begin(), v.end(), mn) - v.begin();
            int num = ind-(n-ind);

            if(num < 0){
                asw.clear();
                asw.push_back(mn);

                equal = 0;

                int sum = 0;
                while(ind+sum < n && v[ind+sum] == mn){
                    equal++;
                    sum++;
                }

            }else if(num == 0){
                asw.push_back(mn);

                int sum = 0;
                while(ind+sum < n && v[ind+sum] == mn){
                    equal++;
                    sum++;
                }
            }
            mn++;
        }

        cout << asw[0] << " " << equal << " " << asw.size() << endl;
    }
}