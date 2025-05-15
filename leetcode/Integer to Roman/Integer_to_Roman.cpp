class Solution {
public:
    string intToRoman(int num) {
        int n[13] = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
        string r[13] = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};

        int idx = 12;
        string ans = "";
        while(num){
            if(n[idx] <= num){
                ans += r[idx];
                num -= n[idx];
            }else{
                idx--;
            }
        }
        return ans;
    }
};
