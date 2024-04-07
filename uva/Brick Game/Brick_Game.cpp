#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int t;
    cin >> t;

    int test = 1;
    while(t--){
        int n;
        cin >> n;
    
        vector<int> v;
        for(int i = 0; i != n; i++){
            int num;
            cin >> num;
            v.push_back(num);
        }

        sort(v.begin(), v.end());
        cout << "Case "<<test<<": "<<v[v.size()/2] << endl;
        test++;
    }
}
