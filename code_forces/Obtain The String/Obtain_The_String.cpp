#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    int t;
    cin >> t;
     
    while(t--){
        string s, t;
        cin >> s >> t;
        
        vector<vector<int> > v(26);
        
        for(int i = 0; i != s.size(); i++){
            v[s[i]-97].push_back(i);
        }

        int index = 0, j = 0, cont = 1;
        
        while(1){
            int ndx_l = t[index]-97;

            if(v[ndx_l].size() == 0){
                cont = -1;
                break;
            }
        
            int k;
            if(binary_search(v[ndx_l].begin(), v[ndx_l].end(), j)){
                k = j;
            }else{
                k = upper_bound(v[ndx_l].begin(), v[ndx_l].end(), j) - v[ndx_l].begin();
                if(k < v[ndx_l].size()){
                    k = v[ndx_l][k];
                }
                else{
                    k = -1;
                }
            }

            if(j <= k){
                j = k+1;
            }else{
                j = 0;
                index--;
                cont++;
            }
            
            index++;

            if(index == t.size()){
                break;
            }
        }

        cout << cont << endl;
    }
}
