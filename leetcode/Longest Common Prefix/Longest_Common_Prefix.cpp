class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = strs[0];

        for(int i = 1; i < strs.size(); i++){
            string save = "";
            for(int j = 0; j != ans.size(); j++){
                if(ans[j] != strs[i][j]){
                    break;
                }
                save += ans[j];
            }

            ans = save;
        }

        return ans;
    }
};
