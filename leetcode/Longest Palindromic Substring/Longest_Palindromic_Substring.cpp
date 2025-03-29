class Solution {
public:
    vector<int> manacher(string s){
        int n = s.length();
        s = "$" + s + "^";
        vector<int> p(n+2);

        int l = 0;
        int r = 1;

        for (int i = 1; i <= n; i++) {
            int mirror = 2 * l - i;

            if (i < r) {
                p[i] = min(r - i, p[mirror]);
            }

            while (s[i +1+ p[i]] == s[i -1- p[i]]) {
                p[i]++;
            }

            if (i + p[i] > r) {
                l = i;
                r = i + p[i];
            }
        }

        return vector<int>(begin(p) + 1, end(p) - 1);
    }

    string longestPalindrome(string s) {
        string save = "";
        for (char c : s) {
            save += "#";
            save += c;
        }
        save += "#";

        vector<int> p = manacher(save);

        int max_length = 0;
        int l_index = 0;
        for (int i = 0; i < save.size(); i++) {
            if (p[i] > max_length) {
                max_length = p[i];
                l_index = i;
            }
        }

        int start_index = (l_index - max_length) / 2;
        string longest_palindrome = s.substr(start_index, max_length);

        return longest_palindrome;
    }
};
