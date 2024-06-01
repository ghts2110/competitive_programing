#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n;
    while(cin >> n){
        if(n==0){
            break;
        }
            
        vector<int> v(n);
        for(int i= 0; i != n; i++){
            cin >> v[i];
        }

        sort(v.begin(), v.end());

        for(int i =0 ;i != n; i++){
            if(i != 0){
                cout << " ";
            }
            cout << v[i];
        }

        cout << endl;
    }
}
