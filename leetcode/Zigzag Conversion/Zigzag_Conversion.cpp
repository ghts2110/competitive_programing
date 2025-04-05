class Solution {
public:
    string convert(string s, int numRows) {
        int n = s.size();
        vector<vector<char>> v(numRows);
        
        if(numRows == 1){
            return s;
        }

        int row = 0, p= 1;
        for(char c : s){
            v[row].push_back(c);
            row+=p;

            if(row == numRows){
                row-=2;
                p = -1;
            }
            if(row == -1){
                row+=2;
                p = 1;
            }
        }
        
        string ans = "";
        for(int i = 0; i != numRows; i++){
            for(char c : v[i]){
                ans += c;
            }
        }
        

        return ans;
    }
};
