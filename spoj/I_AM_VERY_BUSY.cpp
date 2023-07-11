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

        vector<vector<int> > v(n, vector<int> (2));
        for(int i = 0; i != n; i++){
            cin >> v[i][0] >> v[i][1];
        }
    
        sort(v.begin(), v.end());

        int cont = 1, p = 0;
        for(int i = 1; i != n; i++){
            if(v[p][0] <= v[i][0] && v[p][1] > v[i][0]){
                if(v[p][1] > v[i][1]){
                    p = i;
                }
            }else{
                cont++;
                p = i;
            }
        }

        cout << cont << endl;
    }
}
