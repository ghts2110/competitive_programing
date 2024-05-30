#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n, m, test = 1;
    while(cin >> n >> m){
        if(n == m && m == 0){
            break;
        }
        cout << "CASE# "<<test<<":" << endl;
        test++;

        vector<int> v;
        for(int i = 0; i != n; i++){
            int num;
            cin >> num;

            v.push_back(num);
        }

        sort(v.begin(), v.end());

        for(int i = 0; i != m; i++){
            int num;
            cin >> num;
            
            int asw = lower_bound(v.begin(), v.end(), num) - v.begin();
            if(v[asw] == num){
                cout << num << " found at " << asw+1 << endl;
            }else{
                cout << num << " not found" << endl;
            }
        }
    }
}
