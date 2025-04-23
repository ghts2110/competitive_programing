class Solution {
public:
    int myAtoi(string s) {
        long long ans = 0, sin = 1;
        bool val = false;

        for(char c : s){
            if((c == '-'||c=='+'||c==' ') && !val){
                if(c == '-'){
                    sin = -1;
                }
                if(c!=' '){
                    val = true;
                }

                continue;
            }else if(c < '0' || c > '9'){
                break;
            }

            val = true;
            ans = ans*10 + (c-'0');

            if(ans*sin > INT_MAX ){
                return INT_MAX;
            }else if(ans*sin < INT_MIN){
                return INT_MIN;
            }
        }


        return ans*sin;
    }
};
