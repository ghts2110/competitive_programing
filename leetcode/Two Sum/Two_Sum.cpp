#include <iostream>
#include <map>
#include <vector>

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, vector<int>> mp; 
        for(int i = 0; i != nums.size(); i++){
            mp[nums[i]].push_back(i);
        }      

        int a, b;
        for(int i = 0; i != nums.size(); i++){
            int num = target-nums[i];
            if(mp[num].size() != 0){
                if(mp[num][0] != i){
                    a = i;
                    b =  mp[num][0];
                    break;
                }else if(mp[num].size() >= 2 && mp[num][1] != i){
                    a = i;
                    b =  mp[num][1];
                    break;
                }
            }
        }  

        if(a > b){
            return {b, a};
        }
        return {a, b};
    }
};
