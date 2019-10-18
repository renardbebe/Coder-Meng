class Solution {
public:
    void reverseString(vector<char>& s) {
        for (int i = 0; i < s.size(); i++) {
            int j = s.size()-1-i;
            if (i < j) {
                swap(s[i], s[j]);
            }
        }
    }
};