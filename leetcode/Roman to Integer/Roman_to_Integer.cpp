class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> r;
        r['I'] = 1;
        r['V'] = 5;
        r['X'] = 10;
        r['L'] = 50;
        r['C'] = 100;
        r['D'] = 500;
        r['M'] = 1000;

        int n = s.size();
        int ans = 0;
        for(int i = 0; i != n; i++){
            if( i+ 1 < s.size() && r[s[i]] < r[s[i+1]]){
                ans -= r[s[i]];
            }else{
                ans += r[s[i]];
            }
        }

        return ans;
    }
};
