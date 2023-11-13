#include <iostream>
#include <vector>
#include <string>

using namespace std;


int main(){
    int n, m;
    while(cin >> n >> m){
        vector<int> v(26);
        for(int i = 0; i != 26; i++){
            cin >> v[i];
        }

        string s1, s2;
        cin >> s1 >> s2;

        vector<vector<long long> > memo(n+1, vector<long long> (m+1));
        for(int i = 0; i != n; i++){
            for(int j  = 0; j != m; j++){
                if(s1[i] == s2[j]){
                    memo[i+1][j+1] = max(memo[i][j] + v[s1[i]-'a'], max(memo[i][j+1], memo[i+1][j]));
                }else{
                    memo[i+1][j+1] = max(memo[i][j+1], memo[i+1][j]);
                }
            }
        }

        long long mx = 0;
        for(auto it : memo){
            for(auto ij : it){
                mx = max(mx, ij);
            }
        }

        cout << mx << endl;
    }
}