#include <iostream>
#include <string>
#include <vector>

using namespace std;

int dp(int x, int y, vector<vector<int>>&v){
    int mn = 1e9;
    int mx = 0;
    int cont2 = 0;
    for(int i = x; i < v.size(); i++){
        int cont = 0;
        if(v[i][y] == 0){
            break;
        }
        cont2++;
        for(int j = y; j < v[i].size(); j++){
            if(v[i][j] == 0){
                break;
            }

            cont++;
            
        }

        mn = min(mn,cont);
        mx = max(mx,cont2 * mn);
    }

    return mx;


}
int main(){
    int t;
    cin >> t;

    string s;
    bool f = true;
    while(t--){
        cin >> s;
        if(!f){
            cout << endl;
        }

        f = false;
        int ln = s.size();
        vector<vector<int>> v(ln, vector<int> (ln));
        for(int i = 0; i != ln; i++){
            v[0][i] = s[i]-'0';
        }

        for(int i = 0; i != ln-1; i++){
            cin >> s;
            for(int j = 0; j != ln; j++){
                v[i+1][j] = s[j]-'0';
            }
        }
        
        int ans = 0;
        for(int i = 0; i != ln; i++){
            for(int j = 0; j != ln; j++){
                if(v[i][j] == 1){
                    ans = max(ans,dp(i, j, v));
                    
                }
            }
        }

        cout << ans << endl;
    }
}
