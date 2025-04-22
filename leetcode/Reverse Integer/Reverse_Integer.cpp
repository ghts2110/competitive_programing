class Solution {
public:
    int reverse(int x) {
        long long ans = 0, s = 1, save = x;
        if(x < 0){
            s = -1;
            save *= -1;
        }

        while(save!=0){
            ans = ans*10 + save%10;
            save /= 10;
        }

        ans *= s;

        if(ans > INT_MAX || ans < INT_MIN){
            return 0;
        }

        return ans;
    }
};
