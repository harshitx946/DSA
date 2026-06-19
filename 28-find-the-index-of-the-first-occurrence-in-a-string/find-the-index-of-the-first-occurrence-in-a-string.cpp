class Solution {
public:
    vector<int> buildLPS(string pattern) {
        int n = pattern.size();
        vector<int> lps(n, 0);

        int len = 0;
        int i = 1;

        while (i < n) {
            if (pattern[i] == pattern[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }

        return lps;
    }

    int strStr(string haystack, string needle) {

        vector<int> lps = buildLPS(needle);

        int i = 0;
        int j = 0;

        while (i < haystack.size()) {

            if (haystack[i] == needle[j]) {
                i++;
                j++;
            }

            if (j == needle.size()) {
                return i - j;
            }
            else if (i < haystack.size() &&
                     haystack[i] != needle[j]) {

                if (j != 0) {
                    j = lps[j - 1];
                } else {
                    i++;
                }
            }
        }

        return -1;
    }
};