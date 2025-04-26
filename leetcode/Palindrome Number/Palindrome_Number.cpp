class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0){
            return false;
        }

        int save = x, div = 1;

        while(save >= 10){
            save/=10;
            div*=10;
        }

        if(div == 1){
            return true;
        }

        while(div != 0){
            if(x/div != x%10){
                return false;
            }

            x -= x/div * div;
            x /= 10;

            div/=100;
        }        

        return true;
    }
};
