class Solution {
public:
    bool dp(int i, int j, string &s, string &p){
        if(j >= p.size() && i >= s.size()){
            return true;
        }

        if(j < p.size()-1 && p[j+1] == '*'){
            bool val = dp(i, j+2, s, p);

            int cont = 0;
            while(i+cont < s.size() && (p[j] == s[i+cont] || p[j] == '.') && val == false){
                val |= dp(i+cont+1, j+2, s, p);
                cont++;
            }

            return val;
        }

        if((j < p.size() &&  i < s.size()) && (p[j] == s[i] || p[j] == '.')){
            return dp(i+1, j+1, s, p);
        }

        return false;      
    }

    bool isMatch(string s, string p) {
        return dp(0, 0, s, p);
    }
};
