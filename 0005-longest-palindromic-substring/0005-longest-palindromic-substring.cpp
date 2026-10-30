class Solution {
public:
    bool isPalindrome(const string& s, int i, int j) {
        while (i < j) {
            if (s[i++] != s[j--]) return false;
        }
        return true;
    }

    string longestPalindrome(string s) {
        int L = (int)s.size();
        if (L == 0) return "";

        int I = 0, J = 0, longestSoFar = 1;

        for (int i = 0; i + longestSoFar <= L; ++i) {
            for (int j = i + longestSoFar; j < L; ++j) {
                if ((j - i + 1) > longestSoFar && isPalindrome(s, i, j)) {
                    I = i;
                    J = j;
                    longestSoFar = j - i + 1;
                }
            }
        }

        return s.substr(I, longestSoFar);
    }
};
