class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i, j, ans = 0;
        map<char, pair<bool, int>> mp;
        for(j = 0, i = 0; j != s.size(); j++){
            if(mp[s[j]].first){
                ans = max(ans, j-i);
                for(;i != mp[s[j]].second+1;i++){
                    mp[s[i]].first = false;
                }
                i = mp[s[j]].second + 1;
            }
            mp[s[j]].first = true;
            mp[s[j]].second = j;
        }
        ans = max(ans, j-i);

        return ans;
    }
};
