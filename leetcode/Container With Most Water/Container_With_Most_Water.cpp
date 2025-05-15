class Solution {
public:
    int maxArea(vector<int>& height) {
        vector<pair<int, int>> vp;

        int n = height.size();
        for(int i = 0; i != n; i++){
            vp.push_back({height[i], i});
        }

        sort(vp.begin(), vp.end());

        vector<pair<int, int>> sw(100001);
        int mn = 1e9, mx = -1;
        
        for(int i = n-1; i != -1; i--){
            mn = min(mn, vp[i].second);
            mx = max(mx, vp[i].second);

            sw[i] = {mn, mx};
        }

        int ans = 0;
        for(int i = 0; i != n; i++){
            int d1 = vp[i].second - sw[i].first;
            d1 *= vp[i].first;

            int d2 = sw[i].second - vp[i].second;
            d2 *= vp[i].first;

            ans = max(ans, max(d1, d2));
        }

        return ans;
    }
};
