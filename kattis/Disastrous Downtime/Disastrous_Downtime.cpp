#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n, k;
    while(cin >> n >> k){
        vector<int> v(n);
        for(int i = 0; i != n; i++){
            cin >> v[i];
        }

        int p = 0, asw = 1, sub = k-1;
        for(int i = 1; i != n; i++){
            if(v[i] - v[p] < 1000){
                if(sub){
                    sub--;
                    continue;
                }

                asw++;
                sub = k-1;
                continue;
            }
            p++;
        }

        cout << asw << endl;
    }

}