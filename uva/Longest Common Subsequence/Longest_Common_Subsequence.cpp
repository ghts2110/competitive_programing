#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    string s1, s2;
    while(getline(cin, s1) && getline(cin, s2)){
        int l1 = s1.size(), l2 = s2.size();
        vector<vector<int> > memo(l1+1, vector<int>(l2+1));

        for(int i = 0; i < l1; i++){
            for (int j = 0; j < l2; ++j) {
                if(s1[i] == s2[j]){
                    memo[i+1][j+1] = max(memo[i][j] + 1, max(memo[i][j+1], memo[i+1][j]));
                }else{
                    memo[i+1][j+1] = max(memo[i][j+1], memo[i+1][j]);
                }
            }
        }

        cout << memo[l1][l2] << endl;
    }
}