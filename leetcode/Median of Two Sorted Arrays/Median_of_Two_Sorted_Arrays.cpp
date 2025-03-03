class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() > nums2.size()){
            return findMedianSortedArrays(nums2, nums1);
        }

        int m = nums1.size(), n = nums2.size();
        int l = 0, r = m;

        while(l <= r){
            int mid1 = (l+r)/2;
            int mid2 = (m+n+1)/2 - mid1;

            int l1, r1, l2, r2;
            if(mid1 == 0){
                l1 = -1e9;
            }else{
                l1 = nums1[mid1-1];
            }

            if(mid1 == m){
                r1 = 1e9;
            }else{
                r1 = nums1[mid1];
            }

            if(mid2 == 0){
                l2 = -1e9;
            }else{
                l2 = nums2[mid2-1];
            }

            if(mid2 == n){
                r2 = 1e9;
            }else{
                r2 = nums2[mid2];
            }

            if(l1 <= r2 && l2 <= r1){
                if((m+n)%2 == 0){
                    return (max(l1, l2) + min(r1, r2))/2.0;
                }else{
                    return max(l1, l2);
                }
            }else if(l1 <= r2){
                l = mid1+1;
            }else{
                r = mid1-1;
            }
        }

        return 0;
    }
};
